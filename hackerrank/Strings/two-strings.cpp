// https://www.hackerrank.com/challenges/two-strings
// Determine if there's a common substring that appears in both A and B. 
// --> Since only need binary classification, I just check if there's any common letter..
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    int n;
    cin >> n;
    cin.ignore();
    for (int i=0; i < n; i++) {
    	string s1, s2;
    	cin >> s1 >> s2;
    	bool hasCommonSubstring(false);
    	for (char c : s1) {
    		if (s2.find(c) != -1)
    			hasCommonSubstring = true;
    	}

    	if (hasCommonSubstring) cout << "YES";
    	else 					cout << "NO";
    	cout << endl;
    }

	return 0;
}
