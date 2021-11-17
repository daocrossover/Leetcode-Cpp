// 42. Trapping Rain Water
// Description:
// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
// In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:
// n == height.length
// 1 <= n <= 2 * 10^4
// 0 <= height[i] <= 10^5

// Monotonic Stack Solution:
// Monotonically decreasing stack
// We could find the first element from the left that is larger than the current number.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stack>
#include <vector>
using std::stack;
using std::vector;
using std::min;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0, res = 0;
        stack<int> st;
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i);
                i++;
            } else {
                // if the current height > the height of top element on the stack
                // there may be pits to contain water
                int t = st.top();
                st.pop();
                if (st.empty()) continue;
                // current top of the stack: left boundry
                // i: right boundry
                // t: pit
                // contained water = width * (min(height[left], height[right]) - height[pit])
                int width = i - st.top() - 1;
                int diff = min(height[st.top()], height[i]) - height[t];
                res += width * diff;
            }
        }
        return res;
    }
};