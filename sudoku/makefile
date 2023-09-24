CXX= g++
CXXFLAGS= -g -Wall -Wextra -Iinclude -std=gnu++11

all: bin/sudoku

bin/sudoku:	obj/main.o obj/sudoku.o
	@$(CXX) $(CXXFLAGS) -O3 -o bin/sudoku obj/*

obj/main.o: src/main.cpp include/sudoku.h
	@$(CXX) $(CXXFLAGS) -O3 -c -o obj/main.o src/main.cpp


obj/sudoku.o: src/sudoku.cpp include/sudoku.h
	@$(CXX) $(CXXFLAGS) -O3 -c -o obj/sudoku.o src/sudoku.cpp

clean:
	@rm bin/sudoku
	@rm obj/*

test: bin/sudoku
	@printf '1quit yes' | bin/sudoku 
	@printf '2quit yes' | bin/sudoku
	@printf '3quit yes' | bin/sudoku
	@printf '4quit yes' | bin/sudoku
