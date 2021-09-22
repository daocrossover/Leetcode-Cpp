// 350. Intersection of Two Arrays II
// Description:
// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

// Constraints:
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

// Follow up:
// 1. What if the given array is already sorted? How would you optimize your algorithm?
// 2. What if nums1's size is small compared to nums2's size? Which algorithm is better?
// 3. What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

// HashMap Solution:
// nums1 len: m, nums2 len: n
// Time Complexity: O(m + n) 
// Space Complexity: O(m)

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> count;
        for (int i = 0; i < nums1.size(); ++i) {
            count[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (count.find(nums2[i]) != count.end() && count[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                count[nums2[i]]--; // deduct by 1 to avoid duplicate
            }
        }
        return res;
    }
};

// Follow up:
// 1. Apply the Solution2, Time Complexity O(max(m, n)). Worst case, for example, would be nums1 = {100}, and nums2 = {1, 2, ..., 100}

// 2. 
// 2.1 Assuming nums1 and nums2 are sorted. Let's say nums1 is m size. Then we should do binary search for every element in nums1. 
// Each lookup is O(logn), and if we do m times, we have O(mlogn).
// If m this is small enough, O(mlogn) < O(max(m, n)). Otherwise, we have to use the previous two pointers method.
// 2.2 Assuming nums1 and nums2 are not sorted. So it's better to apply the Solution1 and use the smaller array to construct the counter hash.
