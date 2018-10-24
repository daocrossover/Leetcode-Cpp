// Using the first cell of every row and column as a flag.
// This flag would determine whether a row or column has been set to zero.
// Time Complexity: O(m*n)
// Space Complexity: O(1)

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        bool isCol = false;
        for (int i = 0; i < m; ++i) {
            // Since first cell for both first row and first column is the same i.e. matrix[0][0]
            // using an additional variable isCol for the first column
            // and using matrix[0][0] for the first row.
            if (matrix[i][0] == 0) isCol = true;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    // If an element is zero,
                    // we set the first element of the corresponding row and column to 0
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // update the elements
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        // see if the first row needs to be set to zero as well
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        // See if the first column needs to be set to zero as well
        if (isCol == true) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};