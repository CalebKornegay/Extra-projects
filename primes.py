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

i = 1
''' Change "Username\\primes.txt" with your desired path'''
with open("C:\\Users\\Username\\primes.txt", "w") as infile:
    mersennePrime = 2**i - 1
    infile.write(f"Base: {i}  Prime: {mersennePrime}\n")
    while(True):
        if(is_Prime(i)):
            mersennePrime = 2**i - 1
            infile.write(f"Base: {i}  Prime: {mersennePrime}\n")
        i += 1
