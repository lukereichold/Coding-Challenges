// https://www.hackerrank.com/challenges/pairs
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int numPairsWithDifference(vector<int> &nums, int K) {
    map<int, int> hash;
    int count(0);
    for (int i=0; i < nums.size(); i++) {
        hash[nums[i]] = i;
    }

    for (int i=0; i < nums.size(); i++) {
        count += hash.count(nums[i] + K);
    }
    return count;
}

int main() {
    int n, k, temp;
    cin >> n >> k;
    vector<int> nums;
    for (int i=0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    cout << numPairsWithDifference(nums, k) << endl;
    return 0;
}

