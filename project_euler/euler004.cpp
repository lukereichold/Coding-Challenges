// Project Euler - Problem 4 - Largest palindrome product
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
  bool isPalindrome = true;
  for (int i=0; i < s.size(); i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      isPalindrome = false;
    }
  }
  return isPalindrome;
}

int main() {
  int max(0);
  for (int i=100; i < 999; i++) {
    for (int j=100; j < 999; j++) {
        int product = i*j;
        if (product > max && isPalindrome(to_string(product)))
          max = product;
    }
  }  
  cout << "largest palindrome product: " << max << endl;
  return 0;
}
