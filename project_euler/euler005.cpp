// Project Euler - Problem 5: Smallest Multiple
#include <iostream>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    int temp = gcd(a, b);
    if (temp != 0) {
        return a / (temp * b);
    } else {
        return 0;
    }
}

int main() {
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int result = accumulate(arr, arr+8, 1, lcm);
    cout << result << endl;
    return 0;
}