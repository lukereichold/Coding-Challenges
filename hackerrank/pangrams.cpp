// https://www.hackerrank.com/challenges/pangrams
// Determine if a given sentence is a pangram
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {

	string sentence;
	getline(cin, sentence);
	bool characterSeen[26]; // assuming English alphabet
	for (char c : sentence) {
		int index = toupper(c) - 'A';
		if (!isspace(c))
			characterSeen[index] = true;
	}
	bool isPangram(true);
	for (bool b : characterSeen) {
		if (!b) {
			isPangram = false;
			break;
		}
	}
	if (!isPangram) cout << "not ";
	cout << "pangram" << endl;

	return 0;
}