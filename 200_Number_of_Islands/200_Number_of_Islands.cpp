#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {
    void dfs(vector<vector<char>> grid, vector<vector<int>>& visited, int i, int j) {
        visited[i][j] = 1;
        //cout << "visited" << i << j << endl;
        //static_cast<std::vector<char, std::allocator<char>>::size_type>(j)
        if (j + 1 < visited[i].size() &&
            !visited[i][j + 1] &&
            grid[i][j + 1] == '1') {
            dfs(grid, visited, i, j + 1);
        }
        if (i + 1 < visited.size() &&
            !visited[i + 1][j] &&
            grid[i + 1][j] == '1') {
            dfs(grid, visited, i + 1, j);
        }
        if (j - 1 < visited[i].size() &&
            !visited[i][j - 1] &&
            grid[i][j - 1] == '1') {
            dfs(grid, visited, i, j - 1);
        }
        if (i - 1 < visited.size() &&
            !visited[i - 1][j] &&
            grid[i - 1][j] == '1') {
            dfs(grid, visited, i - 1, j);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(
            grid.size(),
            vector<int>(grid[0].size(), 0)
        );

        int islands_num = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    // search
                    //cout << "dfs begins" << endl;
                    dfs(grid, visited, i, j);
                    islands_num++;
                }
            }
        }

        return islands_num;
    }
};

class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        //cout << "visited" << i << j << endl;
        //static_cast<std::vector<char, std::allocator<char>>::size_type>(j)
        if (j + 1 < grid[i].size() &&
            grid[i][j + 1] == '1') {
            dfs(grid, i, j + 1);
        }
        if (i + 1 < grid.size() &&
            grid[i + 1][j] == '1') {
            dfs(grid, i + 1, j);
        }
        if (j - 1 < grid[i].size() &&
            grid[i][j - 1] == '1') {
            dfs(grid, i, j - 1);
        }
        if (i - 1 < grid.size() &&
            grid[i - 1][j] == '1') {
            dfs(grid, i - 1, j);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int islands_num = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    // search
                    //cout << "dfs begins" << endl;
                    dfs(grid, i, j);
                    islands_num++;
                }
            }
        }

        return islands_num;
    }
};

int main() {
    vector <vector< char >> grid = {
        //{'1','1','0','0','0'},
        //{'1','1','0','0','0'},
        //{'0','0','1','0','0'},
        //{'0','0','0','1','1'},
        //{'1','1','1','1','0'},
        //{'1','1','0','1','0'},
        //{'1','1','0','0','0'},
        //{'0','0','0','0','0'},
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'},
    };
    Solution solution;

    cout << solution.numIslands(grid) << endl;

    return 0;
}