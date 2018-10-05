// Description:
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example:
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]


// Backtracking Solution:

#include<vector>
using namespace std;

class Solution {
    vector<int> diagonal1;
    vector<int> diagonal2;
    vector<int> column;
public:
    int totalNQueens(int n) {
        diagonal1.resize(2*n + 1);
        diagonal2.resize(2*n + 1);
        column.resize(n);
        int count = 0;
        backtrack(count, 0, n);
        return count;
    }
    
    bool isValid (int row, int col, int n) {
        // In the same diagonal(45 degrees): row + col = C
        // In the same diagonal(-45 degrees): row - col + n = C
        // So use two diagonal vectors and a column vector
        if (diagonal1[row + col] == 0 && diagonal2[row - col + n] == 0 && column[col] == 0)
            return true;
        return false;
    }
    
    void backtrack (int& count, int row, int n) {
        if (row == n) {
            count++;
        } else {
            for (int col = 0; col < n; ++col) {
                if (isValid(row, col, n)) {
                    diagonal1[row + col] = 1;
                    diagonal2[row - col + n] = 1;
                    column[col] = 1;
                    backtrack(count, row+1, n);
                    diagonal1[row + col] = 0;
                    diagonal2[row - col + n] = 0;
                    column[col] = 0;
                }
            }
        }
    }
};