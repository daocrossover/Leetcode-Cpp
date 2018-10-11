// Dynamic Programming Solution:
// Time Complexity: O(n), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int res = 0;
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max[0] = height[0];
        // Find maximum height of bar from the left end upto an index i in the array left_max
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(height[i], left_max[i-1]);
        }
        right_max[n-1] = height[n-1];
        // Find maximum height of bar from the right end upto an index i in the array right_max
        for (int i = n-2; i >= 0; --i) {
            right_max[i] = max(height[i], right_max[i+1]);
        }
        // add min(left_max[i], right_max[i]) - height[i] to res
        for (int i = 0; i < n; ++i) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};