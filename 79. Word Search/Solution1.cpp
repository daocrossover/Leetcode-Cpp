// Description:
// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.

// Example:
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.


// Backtracking Solution:

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (word[0] == board[i][j] && backtrack(board, visited, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int i, int j, int index) {
        // match in the end
        if (index == word.length())
            return true;
        // (i, j) over boundry or (i, j) has been visited or doesn't match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
            || visited[i][j] || board[i][j] != word[index])
            return false;
        visited[i][j] = true;
        if (backtrack(board, visited, word, i-1, j, index+1) ||
            backtrack(board, visited, word, i+1, j, index+1) ||
            backtrack(board, visited, word, i, j-1, index+1) ||
            backtrack(board, visited, word, i, j+1, index+1))
            return true;
        visited[i][j] = false;
        return false;
    }
};