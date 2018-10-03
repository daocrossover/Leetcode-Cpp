// Description:
// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down.
// You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

// Example 1:
// Input: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Example 2:
// Input: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

// DFS solution:

#include<vector>
using namespace std;

class Solution {
    vector<vector<int>> dir;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // The key is to cache the distance because it's highly possible to revisit a cell
        vector<vector<int>> cache(m, vector<int>(n));
        int maxLen = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Do DFS from every cell
                int len = dfs(matrix, cache, i, j, m, n);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int i, int j, int m, int n) {
        if (cache[i][j] != 0) return cache[i][j];
        int maxLen = 1;
        for (auto d : dir) {
            // Compare every 4 direction and skip cells that are out of boundary or smaller
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j])
                continue;
            int len = 1 + dfs(matrix, cache, x, y, m, n);
            maxLen = max(maxLen, len);
        }
        cache[i][j] = maxLen;
        return maxLen;
    }
};