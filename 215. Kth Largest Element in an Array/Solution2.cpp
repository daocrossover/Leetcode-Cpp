#include <vector>
#include <random>
using std::vector;
using std::default_random_engine;

// QuickSelect Solution:
// Time Complexity: O(n) (best), O(n^2) (worst)
// Space Complexity: O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 1. randomize the array first
        unsigned seed = 0;
        shuffle(nums.begin(), nums.end(), default_random_engine(seed));
        k = nums.size() - k;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            // partition
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

private:
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