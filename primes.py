import os
import math
import sys
sys.set_int_max_str_digits(1000000000)


def is_Prime(n):
    if(n <= 1): return False
    if(n == 2 or n == 3): return True
    if (n % 2 == 0 or n % 3 == 0): return False
    i = 5
    max = math.isqrt(n)
    for i in range(5, max, 6):
        if(n % i == 0 or n % (i+2) == 0): return False
    return True

with open("C:\\Users\\Caleb\\mersennes.txt", "w") as outfile:
    with open("C:\\Users\\Caleb\\OneDrive\\Documents\\knownMersennes.txt", "r") as infile:
        while(infile):
            i = int(infile.readline())
            mersennePrime = 2**i - 1
            outfile.write(f"Base: {i}\tPrime: {mersennePrime}\n")
