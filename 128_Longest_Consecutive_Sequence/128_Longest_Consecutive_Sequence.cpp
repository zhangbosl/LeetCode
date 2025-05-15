#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> nums_map;

        for (const int& num : nums) {
            //nums_map.insert({ num, num });
            nums_map.emplace(num, num);
        }

        int longest = 0;
        //for (const std::pair<int, int>& pair : nums_map) {
        for (const auto& [key, value] : nums_map) {
            if (nums_map.count(key - 1)) {
                continue;
            }
            int length = 1;
            int num = value;
            while (nums_map.count(++num)) {
                length++;
            }
            longest = longest >= length ? longest : length;
        }

        return longest;
    }
};

int main() {
    vector<int> nums = { 
        //100, 4, 200, 1, 3, 2 
        //0,3,7,2,5,8,4,6,0,1
        1,0,1,2
    };
    Solution solution;

    cout << solution.longestConsecutive(nums) << endl;

    return 0;
}