// Calculate the longest increasing subsequence (LIS) of a given sequence of numbers.
#include <iostream>
#include <vector>
using namespace std;

void calc_LIS(vector<int>& nums) {
	// Keep vector to maintain the LIS ending with each nums[i]
	vector<vector<int>> L(nums.size());

	L[0].push_back(nums[0]); // base case, LIS[0] is just the 1st element

	for (int i=1; i < nums.size(); i++) {
		for (int j=0; j < i; j++) {
			if (nums[j] < nums[i] && (L[i].size() < L[j].size() + 1)) {
				L[i] = L[j];
			}
		}
		L[i].push_back(nums[i]);
	}

	auto longest = *max_element(begin(L), end(L), 
					[](const vector<int>& a, const vector<int>& b) {
						return a.size() < b.size();
					});

	for (auto x: longest) {
		cout << x << " ";
	}
}

int main() {
	vector<int> nums {2, 1, 5, 8, 6, 3, 10, 9};
	calc_LIS(nums);
	return 0;
}
