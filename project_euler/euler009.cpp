// Project Euler 9: Special Pythagorean triplet
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // brute force approach
    for (int a = 1; a < 998; a++) {
        for (int b = a+1; b < 999; b++) {
            for (int c = b+1; c < 998; c++) {
                if (pow(a, 2) + pow(b, 2) == pow(c, 2)) { // pythag triplet
                    if (a + b + c == 1000) { // special condition
                        cout << "Product is: " << a * b * c << endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}