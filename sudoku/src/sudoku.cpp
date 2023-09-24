// Aaron King
// Caleb Kornegay
// Cody Allen
// 11/20/2022
// Started on 11/15/2022

#include "sudoku.h"
using namespace std;

Sudoku::Sudoku(int difficulty) {
	srand(clock());
	int row = 0;
	int col = 0;
	int key = 0;

	int given;
	if(difficulty == 1) given = 40;
	else if(difficulty == 2) given = 32;
	else if(difficulty == 3) given = 28;
	else if (difficulty == 4) given = 24;
	else given = 40;

	// Generate the puzzle
	cout << endl;
	printf("Generating puzzle.....");
	
	while(true){
		// Put in 9 random cells until it can be solved
		for(int i = 0; i < 9; i++){
			row = rand() % 9;
			col = rand() % 9;
			key = rand() % 9 + 1;
			if(board[row][col].val == 0){
				board[row][col].val = key;
				if(!isValid()){
					board[row][col].val = 0;
					i--;
				}
			}
			else i--;
		}
		// If it can be solved break, else clear it 
		if(Recursive_Solve(0,0)) break;
		else Delete();
	}
	// Remove cells until we get to the difficulty rating
	for(int i = 0; i < 81-given; i++){
		row = rand() % 9;
		col = rand() % 9;
		key = rand() % 9 + 1;
		if(board[row][col].val != 0) {
			board[row][col].val = 0;
			board[row][col].canEdit = true;
		}
		else i--;
	}
}


// Insert a key if it's int he correct spot
inline void Sudoku::insert_key(int row, int col, int key) {
	if(board[row][col].val == 0) {
		board[row][col].val = key;
	}
	else {
		cout << "Slot is already filled!" << endl;
	}
}

// Removes a key if the player put it in the wrong spot
inline void Sudoku::erase_key(int row, int col) {
	if(board[row][col].canEdit){
		board[row][col].val = 0;
	}
	else{
		cout << "Cannot change that slot!" << endl;
	}
}
// Plays the game implementing all of the member functions.
void Sudoku::play() {

	int row = 0;
	int col = 0;
	int key = 0;

	int loops;
	string response;
	while(true){
		print();
		loops = 0;
		while(true){
			// Error check here
			if(loops == 0){
				cout << "Would you like to insert or delete a key, clear the board, or quit? ";
				cin >> response;
			}
			if(response != "quit" && response != "delete" && response != "insert" && response != "clear") continue;
			if(response == "quit") break;
			if(response == "insert"){
				cout << "Enter the row, column, and key: ";
				cin >> row >> col >> key;
			}
			else if(response == "clear"){
				cout << "Clearing the board...\n";
				Clear();
			}
			else {
				cout << "Enter the row and column: ";
				cin >> row >> col;
			}
			loops++;
			// Clear input until we get what we want
			if(cin.fail()){
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			else break;
		}
		if(response == "quit") break;
		// Error checking the row, col, and key
		if (row > 8 || row < 0) {
			cout << "Invalid row input!" << endl;
			continue;
		}
		if (col > 8 || col < 0) {
			cout << "Invalid column input!" << endl;
			continue;
		}
		if ((key > 9 || key < 1) && response == "insert") {
			cout << "Invalid key input!" << endl;
			continue;
		}
		if(response == "insert") insert_key(row, col, key);
		else erase_key(row, col);
		if(isFull()) break;
	}
	// Check to see if the board is full and is a valid board
	if(checkValid()) cout << "Congrats you won\n";
	else{
		// Asks if they'd like to see the board solved correctly.
		cout << "You did not solve the board correctly\n";
		cout << "Would you like to see how the board is solved (yes/no)? ";
		cin >> response;
		if(response != "yes") return;
		else solve();
	}
}

// Printing the board
void Sudoku::print() const{
	cout << endl;
	for(int i = 0; i < 9; i++){
		if(i == 0) cout << "  ";
		if(i % 3 == 0) cout << "  ";
		cout << i << " ";
	}
	cout << endl;
	for(int i = 0; i < 9; i++) {
		// Printing the horizontal border line
		if((i) % 3 == 0 || i == 0) {
			cout << "  ";
			for(int k = 0; k < 25; k++) {
				cout << '-';
			}
			cout << endl;
		}
		// Printing the values in the board
		for(int j = 0; j < 9; j++) {
			// Printing the vertical border line
			if((j) % 3 == 0 || j == 0) {
				if(j == 0) cout << i << " ";
				cout << "| ";
			}
			if(board[i][j].val == 0)
				cout << "- ";
			else
				cout << board[i][j].val << " ";
		}
		cout << "|" << endl;
	}
	// Printing the bottom border line
	cout << "  ";
	for(int k = 0; k < 25; k++) {
		cout << '-';
	}
	cout << endl;

}

// Checks all the cells to see if it's full
inline bool Sudoku::isFull() const{

	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if(board[i][j].val == 0) {
				return false;
			}
		}
	}

	return true;
}


// Uses mutex (sets) and vectors and compares their sizes to see
// if there are duplicates in rows, columns, and cells to see 
// if the board is valid, used in constructor and solver
inline bool Sudoku::isValid() const{
	unordered_set<int> ust_row, ust_col, ust_cell;
	vector<int> vec_row, vec_col, vec_cell;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			// Row check
			if(board[i][j].val != 0){
				vec_row.push_back(board[i][j].val);
				ust_row.insert(board[i][j].val);
			}
			// Column check
			if(board[j][i].val != 0){
				vec_col.push_back(board[j][i].val);
				ust_col.insert(board[j][i].val);
			}
			// Cell check
			if(board[(i/3)*3+(j%3)][((i%3)*3+(j/3))].val != 0){
				vec_cell.push_back(board[(i/3)*3+(j%3)][((i%3)*3+(j/3))].val);
				ust_cell.insert(board[(i/3)*3+(j%3)][((i%3)*3+(j/3))].val);
			}
		}
		if(vec_row.size() != ust_row.size()) return false;
		if(vec_col.size() != ust_col.size()) return false;
		if(vec_cell.size() != ust_cell.size()) return false;
		vec_row.clear();
		ust_row.clear();
		vec_col.clear();
		ust_col.clear();
		vec_cell.clear();
		ust_cell.clear();
	}
	return true;
}

//Check to see if the space is safe before inserting stuff for solving
inline bool Sudoku::canPlace(int& row, int& col, int& checkVal) const{
	for(int i = 0; i < 9; i++) if(board[row][i].val == checkVal || board[i][col].val == checkVal) return false;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i+row/3*3][j+col/3*3].val == checkVal) return false;
		}
	}
	return true;
}

// Implementation of Plank's recursive sudoku solver
// to help generate boards and solve them for the game
bool Sudoku::Recursive_Solve(int row, int col){

	int i;
	while(row < 9 && board[row][col].val != 0){
		col++;
		if(col == 9){
			row++;
			col = 0;
		}
	}

	if(row == 9) return true;

	for(i = 1; i < 10; i++){
		// Check to see if you can place it before you place it there
		if(canPlace(row, col, i)){
			board[row][col].val = i;
			if(Recursive_Solve(row, col)) return true;
		}
	}
	// Backtrack
	board[row][col].val = 0;
	return false;
}

// Check if it's a correct board
inline bool Sudoku::checkValid() const{
	return isValid() && isFull();
}

// Clear the board, solve it, then print it
void Sudoku::solve(){
	Clear();
	Recursive_Solve(0, 0);
	flush(cout);
	print();
}

// Remove everything on the board, used for generating boards
inline void Sudoku::Delete(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			board[i][j].val = 0;
			board[i][j].canEdit = false;
		}
	}
}

// Clears the board, allows the user to clear
// all the cells that they have placed.
inline void Sudoku::Clear(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(board[i][j].canEdit) board[i][j].val = 0;
		}
	}
}
