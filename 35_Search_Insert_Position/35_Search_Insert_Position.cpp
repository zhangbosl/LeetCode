#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = -1;
        int begin_pos = 0, end_pos = nums.size();
        for (; begin_pos < end_pos;) {
            int middle_pos = (begin_pos + end_pos) / 2;
            if (nums[middle_pos] < target) {
                begin_pos = middle_pos+1;
            }
            else if (nums[middle_pos] > target) {
                end_pos = middle_pos;
            }
            else {
                result = middle_pos;
                break;
            }
        }
        if (result == -1) {
            result = end_pos;
        }
        return result;
    }
};

int main() {
    vector<int> input = { 0,2,4,6,8,10 };
    int target = 7;

    Solution searchInsertPosition;
    int result = searchInsertPosition.searchInsert(input, target);

    cout << "Output: " << result << endl;
    return 0;
}
