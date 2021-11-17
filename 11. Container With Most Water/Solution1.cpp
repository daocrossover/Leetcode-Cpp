// 11. Container With Most Water
// Description:
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
// Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

// Notice that you may not slant the container.

// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:
// Input: height = [1,1]
// Output: 1

// Example 3:
// Input: height = [4,3,2,1,4]
// Output: 16

// Example 4:
// Input: height = [1,2,1]
// Output: 2

// Constraints:
// n == height.length
// 2 <= n <= 10^5
// 0 <= height[i] <= 10^4

// Two pointers Solution:
// Initially consider the maxLength between lines, move the pointer at the longer line inwards,
// we won't gain any increase in area, since it is limited by the shorter line.
// But moving the shorter line's pointer could turn out to be beneficial
// Time complexity: O(n)
// Space complexity: O(1)

#include<vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int m = 0;
        while (left < right) {
            m = max(m, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return m;
    }
};