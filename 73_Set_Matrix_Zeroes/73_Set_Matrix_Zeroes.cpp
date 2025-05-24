#include <iostream>
#include <vector>
#include "../utils/printer.h"

using namespace std;
Printer printer;

class Solution0 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fisrt_nonzero_row = -1;
        int fisrt_nonzero_col = -1;
        for (int i = 0; i < matrix.size(); i++) {
            bool non_zero = true;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    non_zero = false;
                    break;
                }
            }
            if (non_zero) {
                fisrt_nonzero_row = i;
                break;
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            bool non_zero = true;
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][j] == 0) {
                    non_zero = false;
                    break;
                }
            }
            if (non_zero) {
                fisrt_nonzero_col = j;
                break;
            }
        }

        if (fisrt_nonzero_row == -1 || fisrt_nonzero_col == -1) {
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
            return;
        }

        //cout << fisrt_nonzero_row << ' ' << fisrt_nonzero_col << endl;
        //cout << printer.printResult(matrix) << endl;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i == fisrt_nonzero_row || j == fisrt_nonzero_col) {
                    continue;
                }
                if (matrix[i][j] == 0) {
                    matrix[fisrt_nonzero_row][j] = matrix[i][fisrt_nonzero_col] = 0;
                }
                //cout << i << ' ' << j << endl;
                //cout << printer.printResult(matrix) << endl;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][fisrt_nonzero_col] == 0) {
                //if (i < fisrt_nonzero_row || matrix[i][fisrt_nonzero_col] == 0) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[fisrt_nonzero_row][j] == 0) {
                //if (j < fisrt_nonzero_col || matrix[fisrt_nonzero_row][j] == 0) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
}; 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fisrt_nonzero_row = -1;
        int fisrt_nonzero_col = -1;
        for (int i = 0; i < matrix.size(); i++) {
            bool non_zero = true;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    non_zero = false;
                    break;
                }
            }
            if (non_zero) {
                fisrt_nonzero_row = i;
                break;
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            bool non_zero = true;
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][j] == 0) {
                    non_zero = false;
                    break;
                }
            }
            if (non_zero) {
                fisrt_nonzero_col = j;
                break;
            }
        }

        if (fisrt_nonzero_row == -1 || fisrt_nonzero_col == -1) {
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
            return;
        }

        //cout << fisrt_nonzero_row << ' ' << fisrt_nonzero_col << endl;
        //cout << printer.printResult(matrix) << endl;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i < fisrt_nonzero_row && j < fisrt_nonzero_col) {
                    continue;
                }
                if (i == fisrt_nonzero_row || j == fisrt_nonzero_col) {
                    continue;
                }
                if (matrix[i][j] == 0) {
                    matrix[fisrt_nonzero_row][j] = matrix[i][fisrt_nonzero_col] = 0;
                }
                //cout << i << ' ' << j << endl;
                //cout << printer.printResult(matrix) << endl;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            //if (matrix[i][fisrt_nonzero_col] == 0) {
            if (i < fisrt_nonzero_row || matrix[i][fisrt_nonzero_col] == 0) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            //if (matrix[fisrt_nonzero_row][j] == 0) {
            if (j < fisrt_nonzero_col || matrix[fisrt_nonzero_row][j] == 0) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};

int main() {
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    //vector<vector<int>> matrix = { {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
    //vector<vector<int>> matrix = { {0} };
    //vector<vector<int>> matrix = { {8,3,6,9,7,8,0,6} ,{0,3,7,0,0,4,3,8},{5,3,6,7,1,6,2,6},{8,7,2,5,0,6,4,0},{0,2,9,9,3,9,7,3} };

    Solution solution;
    solution.setZeroes(matrix);

    cout << printer.printResult(matrix) << endl;
}
