// Description:
// In a given grid, each cell can have one of three values:
// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange.
// If this is impossible, return -1 instead.

// Example 1:
// Input: [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:
// Input: [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:
// Input: [[0,2]]
// Output: 0
// Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 
// Note:
// 1. 1 <= grid.length <= 10
// 2. 1 <= grid[0].length <= 10
// 3. grid[i][j] is only 0, 1, or 2.

// BFS Solution:

#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::pair;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        }
        int m = grid.size(), n = grid[0].size();
        int fresh_count = 0, days = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    fresh_count++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty() && fresh_count > 0) { // when fresh_count == 0, also finish the loop
            int size = q.size();
            while (size-- > 0) {
                pair<int, int> t = q.front();
                q.pop();
                for (vector<int> d: dirs) {
                    int x = t.first + d[0];
                    int y = t.second + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
                    fresh_count--;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
            days++;
        }
        return fresh_count == 0 ? days : -1;
    }
};