// Follow up 1: O(1) Space Complexity
// live --> die as -1
// die --> live as 2

#include <vector>
using std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> neighbors = {0, 1, -1};
        int m = board.size(), n = board[0].size();
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                int lives = liveNeighbors(board, neighbors, row, col, m, n);
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
    
private:
    int liveNeighbors(vector<vector<int>>& board, vector<int> neighbors, int row, int col, int m, int n) {
        int lives = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                    int r = row + neighbors[i];
                    int c = col + neighbors[j];
                    if (r >= 0 && r < m && c >= 0 && c < n && abs(board[r][c]) == 1) {
                        lives++;
                    }
                }
            }
        }
        return lives;
    }
};