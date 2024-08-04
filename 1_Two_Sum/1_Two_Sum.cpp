#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> index;
        for (int i = 0; i < nums.size(); i++) {
            index.push_back({ nums[i], i });
        }
        //iota(index.begin(), index.end(), 0);
        //qsort(nums, nums.size(), sizeof(int), (int a, int b) { a > b });
        std::sort(index.begin(), index.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
        for (auto it1 = index.begin(), it2 = --index.end(); it1 != it2; ) {
            auto sum = it1->first + it2->first;
            if (sum > target) {
                it2--;
            }
            else if (sum < target) {
                it1++;
            }
            else {
                return vector<int>{it1->second, it2->second};
            }
        }
        return nums;
    }
    vector<int> twoSum_Hash(vector<int>& nums, int target) {
        map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return { it->second, i };
            }
            hashtable[nums[i]] = i;
        }
    }
};

int main() {
    //try {
        //vector<int> nums = { 2, 7, 11, 15 };
        vector<int> nums = { -10, -1, -18, -19 };
        int target = -19;

        Solution solution;
        auto result = solution.twoSum(nums, target);

        string result_string = "[";
        if (!result.empty())
            result_string += "\"" + to_string(result[0]) + "\"";

        for (int i = 1; i < result.size(); ++i)
            result_string += ",\"" + to_string(result[i]) + "\"";

        result_string += "]";

        cout << "Output: " << result_string << endl;
    //}
    //catch (exception e) {
    //    cout << "Exception: " << e.what() << endl;
    //    return -1;
    //}
    return 0;
}