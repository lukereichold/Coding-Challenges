#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    else {
        for (int i=3; i < sqrt(n) + 1; i++) {
            if (n % i == 0) return false;
        }
    }
    return true;
}

int largestPrimeFactor(long n) {
    vector<int> primes;
    int maxPrime(0);
    for (int i=2; i <= sqrt(n); i++) {
        if (isPrime(i)) primes.push_back(i);
    }
    for (int p : primes) {
        if (n % p == 0)
            maxPrime = max(p, maxPrime);
    }
    return maxPrime;
}

int main() {
    cout << largestPrimeFactor(600851475143) << endl;
    return 0;
}