// 289. Game of Life
// Description:
// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). 
// Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// 1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
// 2. Any live cell with two or three live neighbors lives on to the next generation.
// 3. Any live cell with more than three live neighbors dies, as if by over-population.
// 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. 
// Given the current state of the m x n grid board, return the next state.

// Example 1:
// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

// Example 2:
// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]

// Constraints:
// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.

// Follow up:
// 1. Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
// 2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). 
// How would you address these problems?

// Saving the locations where cells need to be changed
// Time Complexity: O(mn)
// Space Complexity: O(mn)
// Also, this is the solution for follow-up 2
// just store the board in a set with coordinates and have board limit m and n

#include <vector>
using std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> coordinates;
        vector<vector<int>> dirs;
        // construct directions array (length of 8)
        vector<int> d = {0, 1, -1};
        for (int x : d) {
            for (int y : d) {
                if (x == 0 && y == 0) continue;
                dirs.push_back(vector<int>{x, y});
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                vector<int> tmp{i, j};
                int count = liveNeighbors(board, dirs, i, j);
                if (board[i][j] == 1 && count < 2 || 
                    board[i][j] == 1 && count > 3 || 
                    board[i][j] == 0 && count == 3) {
                    coordinates.push_back(tmp);
                }
            }
        }
        
        for (auto &point : coordinates) {
            // change the label from 0 to 1 or 1 to 0
            board[point[0]][point[1]] = 1 - board[point[0]][point[1]];
        }
    }
    
    int liveNeighbors(vector<vector<int>>& board, vector<vector<int>>& dirs, int row, int col) {
        int m = board.size(), n = board[0].size();
        int lives = 0;
        for (auto &dir : dirs) {
            int r = row + dir[0];
            int c = col + dir[1];
            if (r >= 0 && r < m && c >= 0 && c < n && abs(board[r][c]) == 1) {
                lives++;
            }
        }
        return lives;
    }
};