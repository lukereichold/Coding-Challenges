#include <iostream>
using namespace std;

unsigned long long getNextNumber(unsigned long long n) {
    if (n % 2 == 0) {
        return n/2;
    } else {
        return 3*n+1;
    }
}

int main() {

    // Better version:
    


    // int maxChainLength(0);
    // int maxChainingSeed(0);
    // for (int start=1; start <= 1000000; start++) {
    //     unsigned long long term = start;
    //     int chainLength(1);
    //     while ((term = getNextNumber(term))) {
    //         if (term == 1) break;
    //         else chainLength++;
    //     }
    //     if (chainLength > maxChainLength)  {
    //         maxChainingSeed = start;
    //         maxChainLength = chainLength;
    //     }
    // }
    // cout << maxChainingSeed << endl;
}