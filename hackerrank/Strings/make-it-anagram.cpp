// https://www.hackerrank.com/challenges/make-it-anagram
// Given two strings (they can be of same or different length), find the minimum number of
// character deletions required to make two strings anagrams.
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	// Find the characters common to both strings
	int frequency1[26] = {0};
	int frequency2[26] = {0};

	for (char c : str1) {
		frequency1[c-'a']++;
	}
	for (char c : str2) {
		frequency2[c-'a']++;
	}

	int numCuts(0);
	for (int i=0; i < 26; i++) {
		numCuts += abs(frequency1[i] - frequency2[i]);
	}
	cout << numCuts << endl;
	return 0;
}