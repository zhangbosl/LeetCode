#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<vector<string>> candidates = { 
            {"a", "b", "c"}, 
            {"d", "e", "f"},
            {"g", "h", "i"}, 
            {"j", "k", "l"}, 
            {"m", "n", "o"}, 
            {"p", "q", "r", "s"},
            {"t", "u", "v"}, 
            {"w", "x", "y", "z"}};

        if (!digits.empty())
            result = candidates[digits[0] - '2'];
        for (size_t i = 1; i < digits.length(); i++) {
            auto tmp = stringJoin(result, candidates[digits[i] - '2']);
            result.clear();
            result = tmp;
        }

        return result;
    }

    vector<string> stringJoin(vector<string> candinates, vector<string> prefix) {
        vector<string> results;
        for (size_t i = 0; i < candinates.size(); i++) {
            for (size_t j = 0; j < prefix.size(); j++) {
                results.push_back(candinates[i] + prefix[j]);
            }
        }
        return results;
    }
};

int main() {
    try {
        string input = "23";
        if (input == "0") {
            cout << "Please input" << endl;
            cin >> input;
        }

        Solution letterCombinations;
        vector<string> result = letterCombinations.letterCombinations(input);

        string result_string = "[";
        if (! result.empty())
            result_string += "\"" + result[0] + "\"";

        for (int i = 1; i < result.size(); ++i)
            result_string += ",\"" + result[i] + "\"";

        result_string += "]";

        cout << "Output: " << result_string << endl;
    }
    catch (exception e) {
        cout << "Exception: " << e.what() << endl;
        return -1;
    }
    return 0;
}