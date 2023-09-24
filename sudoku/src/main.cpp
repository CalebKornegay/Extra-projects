// Caleb Kornegay
// 11/20/2022

#include "sudoku.h"

using namespace std;

int main() {

	int given = 1;
	while(true){
		cout << "How difficult would you like the puzzle? 1-4 for easy-extreme: ";
		cin >> given;
		if(cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX , '\n');
		}
		else break;
	}
	Sudoku s(given);
	s.play();
	return 0;
}

