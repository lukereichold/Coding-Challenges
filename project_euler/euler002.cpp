// Euler 002: Find sum of even-valued Fibonacci numbers < 4 million
#include <iostream>
#include <vector>
using namespace std;

const int UPPER_BOUND = 4000000;

void generateFibs(vector<int> &fibs) {
	for (int i=2; i < UPPER_BOUND; i++) {
		int fib = fibs[i-2] + fibs[i-1];
		if (fib > UPPER_BOUND)		
			break;
		else
			fibs.push_back(fib);
	}
}

int sumOfEvenFibs(vector<int> &fibs) {
	int sum(0);
	for (int f : fibs) {
		if (f % 2 == 0)
			sum += f;
	}
	return sum;
}

int main() {
	vector<int> fibs {1, 2};
	generateFibs(fibs);
	cout << sumOfEvenFibs(fibs);
	return 0;
}