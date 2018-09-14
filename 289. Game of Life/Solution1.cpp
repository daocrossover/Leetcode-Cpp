// Description:
// According to the Wikipedia's article: "The Game of Life, also known simply as Life,
// is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
// Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
// Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

// Write a function to compute the next state (after one update) of the board given its current state.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

// Example:
// Input: 
// [
//   [0,1,0],
//   [0,0,1],
//   [1,1,1],
//   [0,0,0]
// ]
// Output: 
// [
//   [0,0,0],
//   [1,0,1],
//   [0,1,1],
//   [0,1,0]
// ]

// Follow up:
// 1. Could you solve it in-place? Remember that the board needs to be updated at the same time:
// You cannot update some cells first and then use their updated values to update other cells.
// 2. In this question, we represent the board using a 2D array.
// In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array.
// How would you address these problems?

#include<vector>
using namespace std;

class Solution {
public:
    int neighborCount(vector<vector<int>>& board, int row, int col) {
        int m = board.size() - 1, n = board[0].size() - 1;
        int count = 0;
        if (row != 0) count += board[row-1][col];
        if (row != 0 && col != 0) count += board[row-1][col-1];
        if (row != 0 && col != n) count += board[row-1][col+1];
        if (col != 0) count += board[row][col-1];
        if (col != n) count += board[row][col+1];
        if (row != m && col != 0) count += board[row+1][col-1];
        if (row != m) count += board[row+1][col];
        if (row != m && col != n) count += board[row+1][col+1];
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> coordinate;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                pair<int, int> tmp(i, j);
                int count = neighborCount(board, i, j);
                if (board[i][j] == 1 && count < 2) coordinate.push_back(tmp);
                if (board[i][j] == 1 && count > 3) coordinate.push_back(tmp);
                if (board[i][j] == 0 && count == 3) coordinate.push_back(tmp);
            }
        }
        
        for (int i = 0; i < coordinate.size(); ++i) {
            if (board[coordinate[i].first][coordinate[i].second] == 1)
                board[coordinate[i].first][coordinate[i].second] = 0;
            else
                board[coordinate[i].first][coordinate[i].second] = 1;
        }
    }
};