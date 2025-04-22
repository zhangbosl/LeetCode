#include <iostream>
#include <vector>
#include <list>
#include <string>
//#include <algorithm>
#include <iterator>
#include <numeric>
//#include <map>
#include "../utils/printer.h"

using namespace std;

class Solution {
    int n;
    vector<vector<string>> _results;
    vector<int> _queen_positions;
public:
    vector<vector<string>> solveNQueens(int n) {
        this->init(n);

        placeOneQueen();

        return _results;
    }
    void init(int n) {
        this->n = n;
        //this->_queen_positions.resize(n);
    }
    void placeOneQueen() {
        for (int pos = 0; pos < 8; pos++) {
            this->_queen_positions.push_back(pos);
            if (this->_queen_positions.size() == this->n) {
                // a solution
                this->appendResult();
                //return;
            }
            // 算好下一步的可选项
            placeOneQueen(this->availablePositions(this->_available_positions));
            this->_queen_positions.pop_back();
        }
    }
    list<int> availablePositions(list<int> _available_positions) {
        // 根据之前的皇后去掉一些值
        int idx = this->_queen_positions.size();
        for (int i = 0; i < idx; i++) {
            //for (int pos : this->_queen_positions) {
            if (this->_queen_positions[i] - (idx - i) > 0)
                _available_positions.remove(this->_queen_positions[i] - (idx - i));
            if (this->_queen_positions[i] + (idx - i) < n + 1)
                _available_positions.remove(this->_queen_positions[i] + (idx - i));
        }
        return _available_positions;
    }
    void appendResult() {
        // 根据之前的皇后去掉一些值
        vector<string> result;
        for (int pos : this->_queen_positions) {
            string line(n, '.');
            //string line('.', this->n);
            line[pos - 1] = 'Q';
            result.push_back(line);
        }
        this->_results.push_back(result);
    }
};

class Solution1 {
    int n;
    vector<vector<string>> _results;
    vector<int> _queen_positions;
    list<int> _available_positions;
public:
    vector<vector<string>> solveNQueens(int n) {
        this->init(n);

        placeOneQueen(this->_available_positions);

        return _results;
    }
    void init(int n) {
        this->n = n;
        this->_available_positions.resize(n);
        iota(this->_available_positions.begin(), this->_available_positions.end(), 1);
        //this->_queen_positions.resize(n);
    }
    void placeOneQueen(list<int> _available_positions) {
        if (_available_positions.size() == 0) {
            return;
        }
        for (int pos : _available_positions) {
            this->_queen_positions.push_back(pos);
            this->_available_positions.remove(pos);
            if (this->_queen_positions.size() == this->n) {
                // a solution
                this->appendResult();
                //return;
            }
            // 算好下一步的可选项
            placeOneQueen(this->availablePositions(this->_available_positions));
            this->_available_positions.push_back(pos);
            this->_queen_positions.pop_back();
        }
    }
    list<int> availablePositions(list<int> _available_positions) {
        // 根据之前的皇后去掉一些值
        int idx = this->_queen_positions.size();
        for (int i = 0; i < idx; i++) {
            //for (int pos : this->_queen_positions) {
            if (this->_queen_positions[i] - (idx - i) > 0)
                _available_positions.remove(this->_queen_positions[i] - (idx - i));
            if (this->_queen_positions[i] + (idx - i) < n + 1)
                _available_positions.remove(this->_queen_positions[i] + (idx - i));
        }
        return _available_positions;
    }
    void appendResult() {
        // 根据之前的皇后去掉一些值
        vector<string> result;
        for (int pos : this->_queen_positions) {
            string line(n, '.');
            //string line('.', this->n);
            line[pos - 1] = 'Q';
            result.push_back(line);
        }
        this->_results.push_back(result);
    }
};

int main() {
    int n = 8;

    Solution solution;
    auto result = solution.solveNQueens(n);

    Printer printer;
    cout << printer.printResult(result) << endl;;
    printer.print_vector(result);

    return 0;
}
