# Project Euler #27 - Quadratic Primes
import sys
import operator
from math import pow, sqrt
from itertools import count, islice

def is_prime(n):
    return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

# brute force approach
max_consecutive_primes = {}
for a in range(-999, 1000):
    for b in range(-999, 1000):
        maxN = 0
        for n in range(sys.maxsize**10):
            val = pow(n,2) + a*n + b
            if not is_prime(val):
                maxN = n-1
                break
        max_consecutive_primes[(a,b)] = maxN


ab_pairs = sorted(max_consecutive_primes.items(), key=operator.itemgetter(1))
print(ab_pairs[-1][0]) # product of this tuple is solution

