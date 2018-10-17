// Description:
// Given n non-negative integers a1, a2, ..., an,
// where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// Example:
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

// Two pointers Solution:
// Initially consider the maxLength between lines, move the pointer at the longer line inwards,
// we won't gain any increase in area, since it is limited by the shorter line.
// But moving the shorter line's pointer could turn out to be beneficial
// Time complexity: O(n), Space complexity: O(1)

#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int m = 0;
        while (left < right) {
            m = max(m, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) left++;
            else right--;
        }
        return m;
    }
};