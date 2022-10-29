#include "gpacalc.h"
using namespace std;

int main(int argc, char** argv){
	gpacalc calc;
	double gpa;
	if(argc != 2){
		cerr << "Usage: ./gpacalc streamName (file or cin), if \"file\" put in file name" << endl;
		return 1;
	}
	if(string(argv[1]) == "file"){
		if(argc != 3){
			cerr << "You didn't specify a file\n";
			return 1;
		}
		ifstream fin;
		fin.open(argv[2]);
		if(fin.fail()) perror(argv[2]);
		calc.getInput(fin);
	}
	else calc.getInput(cin);
	gpa = calc.getGPA();
	cout << "Your GPA is: " << gpa << endl;
	return 0;
}
