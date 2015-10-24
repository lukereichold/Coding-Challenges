// https://www.hackerrank.com/challenges/gem-stones
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	// Basically, find # letters common in each rock
	int numRocks;
	cin >> numRocks;
	cin.ignore();
	int gemElements[26] = {0};
	for (int i=0; i < numRocks; i++) {
		string rock;
		cin >> rock;
		sort(begin(rock), end(rock));
		rock.erase(unique(rock.begin(), rock.end()), rock.end());
		for (char c: rock) {
			gemElements[c-'a']++;
		}
	}

	int numCommonGemElements(0);
	for (int n : gemElements) {
		if (n >= numRocks)
			numCommonGemElements++;
	}
	cout << numCommonGemElements << endl;
	return 0;
}