// Description:
// Given a m x n matrix, if an element is 0, set its entire row and column to 0.
// Do it in-place.

// Example 1:
// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]

// Example 2:
// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]

// Followup:
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?


// Time Complexity: O(m*n)
// Space Complexity: O(m+n)

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> row, col;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        unordered_set<int>::iterator it;
        for (it = row.begin(); it != row.end(); ++it) {
            for (int j = 0; j < n; ++j) {
                matrix[*it][j] = 0;
            }
        }
        
        for (it = col.begin(); it != col.end(); ++it) {
            for (int i = 0; i < m; ++i) {
                matrix[i][*it] = 0;
            }
        }
    }
};