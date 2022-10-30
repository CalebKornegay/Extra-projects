#include "../include/gpacalc.h"
using namespace std;

gpacalc::gpacalc(){
	mGPA = 0.0;
	mMem.resize(0);
	mSize = 0;
	mGPAHOURS = 0;
}

void gpacalc::getInput(istream& in){
		string line;
		while(getline(in, line)){
			mMem.push_back(line);
		}
		mSize = mMem.size();
}

double gpacalc::getGPA(){
	calcGPA();
	return mGPA;
}


void gpacalc::calcGPA(){
	double gpa;
	unsigned int hours;
	stringstream ss;
	for(size_t i = 0; i < mSize; i++){
		ss << mMem.at(i);
		ss >> gpa >> hours;
		mGPAHOURS += hours;
		mGPA += (gpa * (double)hours);
		ss.clear();
	}
	mGPA /= mGPAHOURS;
}
