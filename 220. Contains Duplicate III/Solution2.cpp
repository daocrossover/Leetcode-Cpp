// Bucket Sort Solution:
// Using buckets covering the range of nums with each bucket a width of (t+1). 
// If there are two item with difference <= t, one of the two will happen:
// (1) the two in the same bucket
// (2) the two in neighbor buckets
// Time Complexity: O(n)
// Space Complexity: O(k)

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0 || k < 0) return false;
        unordered_map<long, long> buckets;
        long w = (long)t + 1;
        for (int i = 0; i < nums.size(); ++i) {
            long m = getID(nums[i], w);
            if (buckets.count(m)) {
                return true;
            }
            if (buckets.count(m - 1) && abs(nums[i] - buckets[m - 1]) < w) {
                return true;
            }
            if (buckets.count(m + 1) && abs(nums[i] - buckets[m + 1]) < w) {
                return true;
            }
            buckets[m] = (long)nums[i];
            if (i >= k) {
                buckets.erase(getID(nums[i - k], w));
            }
        }
        return false;
    }
    
private:
    // get the bucket id (negative number should substract 1)
    long getID(long i, long w) {
        return i < 0 ? i / w - 1 : i / w;
    }
};