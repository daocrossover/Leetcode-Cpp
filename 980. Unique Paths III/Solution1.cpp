// Description:
// On a 2-dimensional grid, there are 4 types of squares:
// 1 represents the starting square.  There is exactly one starting square.
// 2 represents the ending square.  There is exactly one ending square.
// 0 represents empty squares we can walk over.
// -1 represents obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

// Example 1:
// Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

// Example 2:
// Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

// Example 3:
// Input: [[0,1],[2,0]]
// Output: 0
// Explanation: 
// There is no path that walks over every empty square exactly once.
// Note that the starting and ending square can be anywhere in the grid.

// Note:
// 1 <= grid.length * grid[0].length <= 20

#include <vector>
using std::vector;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int squares = 0, start_i, start_j;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    squares++;
                } else if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
            } 
        }
        int cur = 0;
        dfs(grid, visited, start_i, start_j, cur, squares);
        return count;
    }
    
private:
    int count = 0;
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int& cur, int square_num) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || 
            visited[i][j] || grid[i][j] == -1) {
            return;
        }
        if (grid[i][j] == 2) {
            if (cur == square_num) count++;
            return;
        }
        if (grid[i][j] == 0) cur++;
        visited[i][j] = true;
        dfs(grid, visited, i - 1, j, cur, square_num);
        dfs(grid, visited, i + 1, j, cur, square_num);
        dfs(grid, visited, i, j - 1, cur, square_num);
        dfs(grid, visited, i, j + 1, cur, square_num);
        visited[i][j] = false;
        cur--;
    }
};