// Project Euler #5 - Smallest multiple
#include <iostream>
#include <limits>

int main() {

    for (int i=20; i < std::numeric_limits<int>::max(); i++) {
        
        bool allDivisible(true);
        for (int j=1; j <= 20; j++) {
            if (i % j != 0) {
                allDivisible = false;
                break;
            }
        }
        if (allDivisible) {
            std::cout << i;
            break;
        }
    }
    return 0;
}
