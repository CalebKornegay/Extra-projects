#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void hexify(string&, unsigned long long&);

int main(int argc, char** argv){
	unsigned long long VA = 0x0;
	unsigned long long satp = 0x0;
	string temp;
	printf("Enter the SATP and then the VA in hex\n");
	cin >> temp;
	hexify(temp, satp);
	printf("SATP = 0x%08lx\n", satp);
	cin >> temp;
	hexify(temp, VA);
	printf("VA = 0x%08lx\n", VA);
	unsigned long long vpn2 = (VA>>30&511)<<3;
	unsigned long long vpn1 = (VA>>21&511)<<3;
	unsigned long long vpn0 = (VA>>12&511)<<3;
	unsigned long long PO = VA&4095;
	printf("VPN[0] = 0x%08lx\n", vpn0);
	printf("VPN[1] = 0x%08lx\n", vpn1);
	printf("VPN[2] = 0x%08lx\n", vpn2);
	unsigned long long pagetable_entry = 0x0;
	unsigned long long PA = 0x0;
	PA = satp << 12 | vpn2;
	printf("Enter this value: 0x%08lx\n", PA);
	printf("Enter the first translation: ");
	cin >> temp;
	hexify(temp, pagetable_entry);
	if(!(pagetable_entry&1)){
		printf("Page fault\n");
		return 1;
	}
	if(pagetable_entry >> 1 & 7){
		PA = pagetable_entry >> 28 << 30 | PO | vpn1>>3<<21 | vpn0>>3<<12;
		printf("found physical address: 0x%08lx\n", PA);
		return 0;
	}
	else{
		PA = pagetable_entry >> 10 << 12 | vpn1;
		printf("Enter this value: 0x%08lx: \n", PA);
		printf("Enter the second translation: ");
		cin >> temp;
		hexify(temp, pagetable_entry);
		if(!(pagetable_entry&1)){
			printf("Page fault\n");
			return 1;
		}
		if(pagetable_entry >> 1 & 7){
			PA = pagetable_entry >> 19 << 21 | PO | vpn0>>3<<12;
			printf("found physical address: 0x%08lx\n", PA);
			return 0;
		}
		else{
			PA = pagetable_entry >> 10 << 12 | vpn0;
			printf("Enter this value: 0x%08lx: \n", PA);
			printf("Enter the third translation: ");
			cin >> temp;
			hexify(temp, pagetable_entry);
			if(!(pagetable_entry&1)){
				printf("Page fault\n");
				return 1;
			}	
			if(pagetable_entry >> 1 & 7){
				PA = ((pagetable_entry >> 10) << 12) | PO;
				printf("found physical address : 0x%08lx\n", PA);
				return 0;
			}
			else{
				printf("Page fault\n");
				return 1;
			}
		}
	}	
}


void hexify(string& var, unsigned long long& dest){
	var.substr(2, var.length());
	stringstream ss;
	ss << var;
	ss >> hex >> dest;
	ss.clear();
}
