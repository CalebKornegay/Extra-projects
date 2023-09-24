// Aaron King
// Caleb Kornegay
// Cody Allen
// Started on 11/15/2022
#pragma once
#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <vector>
#include <unordered_set>
#include <thread>

struct Cell {
	int val;
	bool canEdit;
	Cell() : val(0), canEdit(false) {} // every cell defaults to 0 and can be edited
};



class Sudoku {

	private:
		Cell board[9][9];
		inline void insert_key(int, int, int);
		inline void erase_key(int, int);
		inline bool isFull() const;
		inline bool isValid() const;
		bool Recursive_Solve(int, int);
		inline void Delete();
		inline void Clear();
		void print() const;
		inline bool checkValid() const;
		void solve();
		inline bool canPlace(int&, int&, int&) const;

	public:
		Sudoku(int);
		void play();
};

