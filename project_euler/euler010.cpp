// Project Euler - Problem 10 - Summation of all primes below two million
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    else {
        for (int i=3; i < sqrt(n) + 1; i++) {
            if (n % i == 0)	return false;
        }
    }
    return true;
}

void calculatePrimesBelowTwoMillion(vector<int>& primes) {
    for (int i=2; i < 2000000; i++) {
        if (isPrime(i)) 
            primes.push_back(i);
    }
}

int main() {
    vector<int> primes;
	calculatePrimesBelowTwoMillion(primes);
	unsigned long long sum(0);
    for_each(begin(primes), end(primes), [&](int n) {
        sum += n;
    });

    cout << "Sum: " << sum;
    return 0;
}