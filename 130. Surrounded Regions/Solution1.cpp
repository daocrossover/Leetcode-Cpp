// Description:
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example:
// X X X X
// X O O X
// X X O X
// X O X X

// After running your function, the board should be:
// X X X X
// X X X X
// X X X X
// X O X X

// Explanation:
// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
// Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
// Two cells are connected if they are adjacent cells connected horizontally or vertically.

#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        int m = board.size(), n = board[0].size();
        // Any 'O' connected to a boundary can't be turned to 'X'
        // go through the first column and the last column
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        // go through the first row and the last row
        for (int j = 1; j < n - 1; ++j) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        // make all the remaining 'O' to 'X'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '*') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if (board[i][j] == 'X' || board[i][j] == '*') return;
        board[i][j] = '*';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};