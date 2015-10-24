// Project Euler Problem 7 - Find 10001st prime
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    else {
        for (int i=3; i < sqrt(n) + 1; i++) {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}

int nth_prime(int n) {

    vector<int> primes;
    for (int i=2; i < numeric_limits<int>::max(); i++) {
        if (isPrime(i)) primes.push_back(i);
        if (primes.size() == n) break;
    }
    return primes.back();
}

int main() {
    cout << nth_prime(10001);
    return 0;
}