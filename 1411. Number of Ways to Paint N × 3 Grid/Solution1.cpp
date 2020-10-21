// 1411. Number of Ways to Paint N × 3 Grid
// Description:
// You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour 
// (i.e no two cells that share vertical or horizontal sides have the same colour).
// You are given n the number of rows of the grid.
// Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

// Example 1:
// Input: n = 1
// Output: 12
// Explanation: There are 12 possible way to paint the grid as shown:

// Example 2:
// Input: n = 2
// Output: 54

// Example 3:
// Input: n = 3
// Output: 246

// Example 4:
// Input: n = 7
// Output: 106494

// Example 5:
// Input: n = 5000
// Output: 30228214

// Constraints:
// 1. n == grid.length
// 2. grid[i].length == 3
// 3. 1 <= n <= 5000

// Dynamic Programming Solution:
// Two pattern for each row, 121 and 123.
// 121, the first color same as the third in a row.
// 123, one row has three different colors.
// For first row:
// pattern 121: 121, 131, 212, 232, 313, 323.
// pattern 123: 123, 132, 213, 231, 312, 321.
// So we initialize color2 = 6, color3 = 6.
// We consider the next possible for each pattern:
// first row 121 can be followed by: 212, 213, 232, 312, 313
// first row 123 can be followed by: 212, 231, 312, 232
// 121 => three pattern 121, two pattern 123
// 123 => two pattern 121, two pattern 123
// transform equation:
// color2_next = 3 * color2 + 2 * color3
// color3_next = 2 * color2 + 2 * color3

class Solution {
public:
    int numOfWays(int n) {
        long color2 = 6, color3 = 6, mod = 1e9 + 7;
        long color2_next, color3_next;
        for (int i = 1; i < n; ++i) {
            color2_next = 3 * color2 + 2 * color3;
            color3_next = 2 * color2 + 2 * color3;
            color2 = color2_next % mod;
            color3 = color3_next % mod;
        }
        return (int)(color2 + color3) % mod;
    }
};