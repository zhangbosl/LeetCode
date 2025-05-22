#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {

		int plus = 0, count = 0;
		unordered_map<int, int> pre_plus;
		pre_plus[0] = 1;

		for (int i = 0; i < nums.size(); i++) {
			plus += nums[i];
			count += pre_plus[plus - k];
			pre_plus[plus] += 1;
		}

		return count;
	}
};

int main() {
	vector<int> nums = { 1, 2, 3 };
	int k = 3;

	Solution solution;

	cout << solution.subarraySum(nums, k) << endl;

	return 0;
}
