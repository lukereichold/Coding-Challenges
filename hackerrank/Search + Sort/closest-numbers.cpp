// https://www.hackerrank.com/challenges/closest-numbers
// Given a list of unsorted integers, A={a1,a2,…,aN}, can you find the pair of elements
// that have the smallest absolute difference between them? If there are multiple pairs, find them all.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    int nums[n];
    for (int i=0; i < n; i++) {
    	cin >> nums[i];
    }
    sort(nums, nums + n);

    int minDifference = nums[1]-nums[0]; 
    for (int i=2; i < n; i++) {
    	minDifference = min(minDifference, nums[i] - nums[i-1]);
    }
    bool firstPair(true);
    for (int i=1; i < n; i++) {
    	if (nums[i] - nums[i-1] == minDifference) {
    		if (firstPair)	firstPair = false;
    		else   			cout << " "; // make printing nice
    		cout << nums[i-1] << " " << nums[i];
    	}
    }
    cout << endl;
	return 0;
}
