// Two Pointers Solution:
// As long as right_max[i] > left_max[i], the water trapped depends upon the left_max,
// and similar is the case when left_max[i] > right_max[i]
// If there is a larger bar at one end (say right),
// we are assured that the water trapped would be dependant on height of bar in current direction (from left to right).
// As soon as we find the bar at other end (right) is smaller,
// we start iterating in opposite direction (from right to left).

// Time Complexity: O(n), Space Complexity: O(1)

#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            // direction from left to right
            if (height[left] < height[right]) {
                // if height[left] >= left_max, update left_max
                // else res += (left_max - height[left])
                height[left] >= left_max ? (left_max = height[left]) : res += (left_max - height[left]);
                ++left;
            } else {
            // direction from left to right
                // if height[right] >= right_max, update right_max
                // else res += (right_max - height[left])
                height[right] >= right_max ? (right_max = height[right]) : res += (right_max - height[right]);
                --right;
            }
        }
        return res;
    }
};