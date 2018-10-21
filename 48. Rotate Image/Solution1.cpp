// Description:
// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).

// Note:
// You have to rotate the image in-place,
// which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

// Example 1:
// Given input matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]

// Example 2:
// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ], 

// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]


#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        int m = matrix.size(), n = matrix[0].size();
        // swap according to the diagonal
        for (int row = 0; row < m; ++row) {
            for (int col = row + 1; col < n; ++col) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        // swap according to the y axis
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n / 2; ++col) {
                swap(matrix[row][col], matrix[row][n-col-1]);
            }
        }
    }
};