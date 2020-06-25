// Binary Search Solution:
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int a: nums) {
                if (a <= mid) ++cnt;
            }
            if (cnt <= mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};