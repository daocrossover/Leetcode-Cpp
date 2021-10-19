// Follow up 1: In-place Solution
// Space Complexity: O(1)
// live --> die: labelled as -1
// die --> live: labelled as 2

#include <vector>
using std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dirs;
        // construct directions array (length of 8)
        vector<int> d = {0, 1, -1};
        for (int x : d) {
            for (int y : d) {
                if (x == 0 && y == 0) continue;
                dirs.push_back(vector<int>{x, y});
            }
        }
        int m = board.size(), n = board[0].size();
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                int lives = liveNeighbors(board, dirs, row, col);
                if (board[row][col] == 1 && (lives < 2 || lives > 3)) {
                    board[row][col] = -1;
                }
                if (board[row][col] == 0 && lives == 3) {
                    board[row][col] = 2;
                }
            }
        }
        
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (board[row][col] > 0) {
                    board[row][col] = 1;
                } else {
                    board[row][col] = 0;
                }
            }
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