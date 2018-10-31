// Description:
// Given a non-empty 2D matrix matrix and an integer k,
// find the max sum of a rectangle in the matrix such that its sum is no larger than k.

// Example:
// Input: matrix = [[1,0,1],[0,-2,3]], k = 2
// Output: 2 
// Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
//              and 2 is the max number no larger than k (k = 2).

// Note:
// The rectangle inside the matrix must have an area > 0.
// What if the number of rows is much larger than the number of columns?


#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
        for (int l = 0; l < col; ++l) {
            // sum of all elements in a column in [l, r]
            vector<int> sums(row, 0);
            for (int r = l; r < col; ++r) {
                for (int i = 0; i < row; ++i) {
                    sums[i] += matrix[i][r];
                }
                
                // Find the max subarray no more than K
                // sum of subarray (i, j] is just the sum of the first j elements - the sum of the first i elements.
                // Store these cumulative sums in the array cum.
                // Then the problem reduces to finding i,j such that i < j
                // and cum[j]-cum[i] is as close to k but lower than it.
                set<int> st;
                st.insert(0);
                int curSum = 0, curMax = INT_MIN;
                for (int sum : sums) {
                    curSum += sum;
                    set<int>::iterator it = st.lower_bound(curSum - k);
                    if (it != st.end()) curMax = max(curMax, curSum - *it);
                    st.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};