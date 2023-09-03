#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    srand(time(NULL));
    if(argc != 3) {cerr << "Usage: ./gen [#ofNums] [file_name]\n"; return 1;}
    ofstream fout;
    int num_to_gen = stoi(argv[1]);
    fout.open(argv[2]);
    while(num_to_gen--){
        fout << (rand() % 1000) + 1 << endl;
    }
    fout.close();
    return 0;
}