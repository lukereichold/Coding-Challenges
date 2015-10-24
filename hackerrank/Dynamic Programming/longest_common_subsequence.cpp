// Longest Common Subsequence (LCS)
// https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence
#import <iostream>
#import <string>
#import <vector>
using namespace std;

vector<vector<int>> generateTableLCS(string& A, string& B) {
	int m = A.size() + 1;
	int n = B.size() + 1;
	vector<vector<int>> C;
	for (int i=0; i < m; i++) {
		C.push_back(vector<int>(n, 0));
	}
	for (int i=1; i < m; i++) {
		for (int j=1; j < n; j++) {
			if (A[i] == B[j]) {
				C[i][j] = C[i-1][j-1] + 1;
			} else {
				C[i][j] = max(C[i][j-1], C[i-1][j]);
			}
		}
	}
	return C;
}

int main() {

	string a("thisisatest"), b("testing123testing");
	auto table = generateTableLCS(a,b);
	cout << "Length of LCS is " << table[a.size()][b.size()] << endl;
	return 0;
}