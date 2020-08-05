// Description:
// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
// find the area of largest rectangle in the histogram.

// Example:
// Input: [2,1,5,6,2,3]
// Output: 10

// Monotonic Stack Solution:
// monotonically increasing stack
// could find the first element from the left that is smaller than the current number
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stack>
#include <vector>
using std::stack;
using std::vector;
using std::max;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0); // tracking the last element in the stack
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                int cur = st.top();
                st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : i - st.top() - 1));
            }
            st.push(i);
        }
        return res;
    }
};