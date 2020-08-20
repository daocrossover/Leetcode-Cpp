// Description:
// Design a Tic-tac-toe game that is played between two players on a n x n grid.

// You may assume the following rules:
// A move is guaranteed to be valid and is placed on an empty block.
// Once a winning condition is reached, no more moves is allowed.
// A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
 
// Example:
// Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
// TicTacToe toe = new TicTacToe(3);

// toe.move(0, 0, 1); -> Returns 0 (no one wins)
// |X| | |
// | | | |    // Player 1 makes a move at (0, 0).
// | | | |

// toe.move(0, 2, 2); -> Returns 0 (no one wins)
// |X| |O|
// | | | |    // Player 2 makes a move at (0, 2).
// | | | |

// toe.move(2, 2, 1); -> Returns 0 (no one wins)
// |X| |O|
// | | | |    // Player 1 makes a move at (2, 2).
// | | |X|

// toe.move(1, 1, 2); -> Returns 0 (no one wins)
// |X| |O|
// | |O| |    // Player 2 makes a move at (1, 1).
// | | |X|

// toe.move(2, 0, 1); -> Returns 0 (no one wins)
// |X| |O|
// | |O| |    // Player 1 makes a move at (2, 0).
// |X| |X|

// toe.move(1, 0, 2); -> Returns 0 (no one wins)
// |X| |O|
// |O|O| |    // Player 2 makes a move at (1, 0).
// |X| |X|

// toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
// |X| |O|
// |O|O| |    // Player 1 makes a move at (2, 1).
// |X|X|X|
 
// Follow up:
// Could you do better than O(n^2) per move()

// Hint:
// 1. Could you trade extra space such that move() operation can be done in O(1)?
// 2. You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.

#include <vector>
using std::vector;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): rows(n), cols(n), N(n), diag(0), anti_diag(0) {}

    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        rows[row] += add; 
        cols[col] += add;
        diag += (row == col ? add : 0);
        anti_diag += (row == N - col - 1 ? add : 0);
        return (abs(rows[row]) == N || abs(cols[col]) == N || abs(diag) == N || abs(anti_diag) == N) ? player : 0;
    }

private:
    vector<int> rows, cols;
    int diag, anti_diag, N;
};