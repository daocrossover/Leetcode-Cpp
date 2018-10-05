// Description:
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// Example:
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.


// Backtracking Solution:

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> res;
        backtrack(board, res, 0);
        return res;
    }
    
    void backtrack(vector<vector<char>>& board, vector<vector<string>>& res, int row) {
        if (row == board.size()) {
            vector<string> tmp;
            for (int i = 0; i < board.size(); ++i) {
                string str(board[i].begin(),board[i].end());
                tmp.push_back(str);
            }
            res.push_back(tmp);
            return;
        }
        
        for (int col = 0; col < board[0].size(); ++col) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(board, res, row + 1);
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 'Q' && (row + j == col + i || row + col == i + j || col == j))
                    return false;
            }
        }
        return true;
    }
};