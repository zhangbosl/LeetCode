#include <iostream>
#include <vector>
#include <unordered_map>

#include "../utils/printer.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //int* zero = nullptr;
        int* num = &nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                //zero = &nums[i];
                cout << "zero " << i << endl;
                for (num = num > &nums[i]?num: &nums[i]+1; num <= &*nums.rbegin(); num++) {
                    cout << num << " " << *num << endl;
                    if (*num) {
                        break;
                    }
                }
                if (num > &*nums.rbegin()) {
                    break;
                }
                nums[i] = *num;
                *num++ = 0;
            }
        }
    }
};

int main() {
    vector<int> nums = {
        0,1,0,3,12
        //1, 0
    };
    Solution solution;
    Printer printer;

    solution.moveZeroes(nums);
    cout << printer.printResult(nums) << endl;

    return 0;
}