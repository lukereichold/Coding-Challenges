#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream f("vals.txt");
	double sum(0);
	double val;
	for (int i=0; i < 100; i++) {
		f >> val;
		sum += val;
	}

	cout << to_string(sum).substr(0, 10) << endl;
}