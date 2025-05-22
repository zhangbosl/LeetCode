#include <iostream>
#include <vector>

#include "../utils/printer.h"
#include <span>

using namespace std;
Printer printer;

class Solution1 {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		//cout << "in" << printer.printResult(nums) << endl;

		if (nums.size() == 1) {
			for (int num : nums) {
				result.push_back(vector<int>{num});
			}
		}
		else {
			for (int i = 0; i < nums.size(); i++) {
				vector<int> absent;
				for (int j = 0; j < i; j++) {
					absent.push_back(nums[j]);
				}
				for (int j = i+1; j < nums.size(); j++) {
					absent.push_back(nums[j]);
				}
				auto part_result = permute(absent);
				for (vector<int>& tmp : part_result) {
					tmp.push_back(nums[i]);
					result.push_back(tmp);
				}
			}
		}
		//cout << "out" << printer.printResult(result) << endl;

		return result;
	}
};

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums, int first = 0) {
		vector<vector<int>> result;
		//cout << "in" << first << printer.printResult(nums) << endl;

		if (nums.size() == first + 1) {
			result.push_back(vector<int>{nums[first]});
		}
		else {
			for (int i = first; i < nums.size(); i++) {
				int tmp = nums[first];
				nums[first] = nums[i];
				nums[i] = tmp;
				auto part_result = permute(nums, first + 1);
				tmp = nums[first];
				nums[first] = nums[i];
				nums[i] = tmp;
				for (vector<int>& tmp : part_result) {
					tmp.push_back(nums[i]);
					result.push_back(tmp);
				}
			}
		}
		//cout << "out" << printer.printResult(result) << endl;

		return result;
	}
};

int main() {
	vector<int> nums = { 1, 2, 3 };

	Solution solution;
	Printer printer;

	auto result = solution.permute(nums);

	cout << printer.printResult(result) << endl;
}
