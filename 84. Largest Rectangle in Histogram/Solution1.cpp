// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
// find the area of largest rectangle in the histogram.

// Example:
// Input: [2,1,5,6,2,3]
// Output: 10

// Monotonic Stack Solution:
// monotonically increasing stack
// could find the first element from the left that is smaller than the current number
// Time Complexity: O(n), Space Complexity: O(n)

#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i = 0, res = 0;
        // to tackle the last element in the array heights
        heights.push_back(0);
        stack<int> st;
        while (i < heights.size()) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i);
                i++;
            } else {
                int t = st.top();
                st.pop();
                res = max(res, heights[t] * (st.empty() ? i : i - st.top() - 1));
            }
        }
        return res;
    }
};