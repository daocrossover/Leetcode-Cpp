#include <vector>
using std::vector;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (auto d: dir) {
                        int x = i + d[0], y = j + d[1];
                        // each time, we encounter a boundary, count++;
                        if (x < 0 || x == m || y < 0 || y == n || grid[x][y] == 0) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};