// Description:
// Given a 2D binary matrix filled with 0's and 1's,
// find the largest rectangle containing only 1's and return its area.

// Example:
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6


// This question is similar as 84. Largest Rectangle in Histogram
// using monotonic stack:

#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        // record its height of '1's,
        vector<int> height(n+1, 0);
        int res = 0;
        // scan and update row by row to find out the largest rectangle of each row.
        for (int i = 0; i < m; ++i) {
            stack<int> st;
            for (int j = 0; j < n+1; ++j) {
                // For each row i, if matrix[i][j] == '1', height[i]++, or reset the height[i] to zero.
                if (j < n) {
                    if (matrix[i][j] == '0') {
                        height[j] = 0;
                    } else {
                        height[j]++;
                    }
                }
                // more concise than the version in Largest Rectangle in Histogram
                if (st.empty() || height[st.top()] <= height[j]) {
                    st.push(j);
                } else {
                    while (!st.empty() && height[st.top()] > height[j]) {
                        int t = st.top();
                        st.pop();
                        res = max(res, height[t] * (st.empty() ? j : j-st.top()-1));
                    }
                    st.push(j);
                }
            }
        }
        return res;
    }
};