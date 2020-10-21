#include <vector>
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.empty()) return res;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (nums[lo] != target) return res;
        res[0] = lo;
        hi = nums.size() - 1;
        while (lo < hi) {
            // mid + 1 is the trick
            int mid = lo + (hi - lo) / 2 + 1;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        res[1] = lo;
        return res;
    }
};