CC = g++
CFLAGS = -g -Wall -O0

all: main.o gpacalc.o
	$(CC) $(CFLAGS) -o gpacalc main.o gpacalc.o

main.o: main.cpp
	$(CC) -c main.cpp

gpacalc.o:
	$(CC) -c gpacalc.cpp

clean:
	rm -r *.o 
	rm gpacalc
