// Description:
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:
// 1. Each of the digits 1-9 must occur exactly once in each row.
// 2. Each of the digits 1-9 must occur exactly once in each column.
// 3. Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

// Empty cells are indicated by the character '.'.

// Note:
// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique solution.
// The given board size is always 9x9.


// Backtracking Solution:

#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    // trial. Try 1 through 9
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            // Put c for this cell
                            board[i][j] = c;
                            // If it's the solution return true
                            if (solve(board)) return true;
                            // Otherwise go back
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            // check row
            if(board[i][col] != '.' && board[i][col] == c)
                return false;
            // check column
            if(board[row][i] != '.' && board[row][i] == c)
                return false;
            // check 3*3 block
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] != '.' && board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
                return false;
        }
        return true;
    }
};