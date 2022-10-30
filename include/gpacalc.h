#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <istream>
#include <fstream>

class gpacalc{
	public:
		gpacalc();
		double getGPA();
		void getInput(std::istream&);
	private:
		double mGPA;
		size_t mGPAHOURS;
		std::vector<std::string> mMem;
		size_t mSize;
		void calcGPA();
};
