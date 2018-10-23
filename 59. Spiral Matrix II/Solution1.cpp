// Description:
// Given a positive integer n,
// generate a square matrix filled with elements from 1 to n2 in spiral order.

// Example:
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]


#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        if (n == 0) return res;
        int num = 1;
        int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;
        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int j = colStart; j <= colEnd; ++j) {
                res[rowStart][j] = num++;
            }
            rowStart++;
            
            for (int i = rowStart; i <= rowEnd; ++i) {
                res[i][colEnd] = num++;
            }
            colEnd--;

            for (int j = colEnd; j >= colStart; --j) {
                if (rowStart <= rowEnd)
                    res[rowEnd][j] = num++;
            }
            rowEnd--;

            for (int i = rowEnd; i >= rowStart; --i) {
                if (rowStart <= rowEnd)
                    res[i][colStart] = num++;
            }
            colStart++;
        }
        return res;
    }
};