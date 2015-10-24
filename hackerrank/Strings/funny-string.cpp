// https://www.hackerrank.com/challenges/funny-string
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {

    int n;
    cin >> n;
    cin.ignore();
    for (int i=0; i < n; i++) {
    	string str;
    	cin >> str;
    	string rev;
    	for (int i=str.length() - 1; i >= 0; i--) {
    		rev += str[i];
    	}
    	bool isFunny(true);
    	for (int i=1; i < str.length(); i++) {
    		if (abs(str[i] - str[i-1]) != abs(rev[i] - rev[i-1])) {
    			isFunny = false;
    			break;
    		}
    	}
    	if (!isFunny) cout << "Not ";
		cout << "Funny" << endl;
    }
	return 0;
}
