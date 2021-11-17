// Using QuickSelect to find the median
// Time Complexity: O(n) (best), O(n^2) (worst)

#include <vector>
using std::vector;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int median = findKthLargest(nums, n / 2 + 1);
        int moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }
        return moves;
    }
    
private:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int j = partition(nums, lo, hi);
            if (j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }
    
    int partition(vector<int>& nums, int lo, int hi) {
        int pivot = nums[lo];
        while (lo < hi) {
            while (lo < hi && nums[hi] >= pivot) --hi;
            nums[lo] = nums[hi];
            while (lo < hi && nums[lo] <= pivot) ++lo;
            nums[hi] = nums[lo];
        }
        nums[lo] = pivot;
        return lo;
    }
};