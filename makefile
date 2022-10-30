CC = g++
CFLAGS = -g -Wall -O0

all: obj/main.o obj/gpacalc.o
	$(CC) $(CFLAGS) -o bin/gpacalc obj/main.o obj/gpacalc.o

obj/main.o: src/main.cpp include/gpacalc.h
	$(CC) -c -o obj/main.o src/main.cpp

obj/gpacalc.o: src/gpacalc.cpp include/gpacalc.h
	$(CC) -c -o obj/gpacalc.o src/gpacalc.cpp

clean:
	rm -r obj/*.o 
	rm bin/gpacalc
