#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		int max_sum = nums[0];
		//int begin = 0;
		int cur_sum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (cur_sum < 0) {
				//begin = i;
				cur_sum = nums[i];
			}
			else {
				cur_sum += nums[i];
			}
			if (cur_sum > max_sum) {
				max_sum = cur_sum;
			}
		}
		return max_sum;
	}
};

int main() {
	//vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> nums = { 5,4,-1,7,8 };

	Solution solution;

	cout << solution.maxSubArray(nums) << endl;

	return 0;
}
