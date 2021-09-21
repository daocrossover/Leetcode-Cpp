// 480. Sliding Window Median
// Description:
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
// So the median is the mean of the two middle values.

// For examples, if arr = [2,3,4], the median is 3.
// For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
// You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the median array for each window in the original array. Answers within 10^-5 of the actual value will be accepted.

// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
// Explanation: 
// Window position                Median
// ---------------                -----
// [1  3  -1] -3  5  3  6  7        1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7        3
//  1  3  -1  -3 [5  3  6] 7        5
//  1  3  -1  -3  5 [3  6  7]       6

// Example 2:
// Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
// Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]

// Constraints:
// 1. 1 <= k <= nums.length <= 10^5
// 2. 2^31 <= nums[i] <= 2^31 - 1


// Two Mulitiset Solution:
// First thinking is to use two heaps (max-heap and min-heap), but need to remove the number out of the window.
// And stl priority_queue do not have the remove function, so we use two treesets (std::multiset)
// Create two treesets (ordered), store left and right part of arrays (split by median)
// the size of upper is larger than that of lower but will not exceed 1
// when k = odd number, the median is the first element of upper
// when k = even number, the median is the average of the last element of lower and first element of upper

// Time Complexity: O(nlogk) since TreeSet remove element O(logk)
// Using Priority Queue (Java) remove element O(k), so the time complexity will be O(nk)
// Space Complexity: O(k)

#include <vector>
#include <set>
using std::vector;
using std::multiset;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> lower, upper;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // insert new number
            if (upper.empty() || nums[i] >= *upper.begin()) {
                upper.insert(nums[i]);
            } else {
                lower.insert(nums[i]);
            }
            
            // remove number out of the window
            if (i >= k) {
                if (nums[i - k] >= *upper.begin()) {
                    upper.erase(upper.find(nums[i - k]));
                } else {
                    lower.erase(lower.find(nums[i - k]));
                }
            }
            
            // balance the size of two sets
            if (upper.size() < lower.size()) {
                upper.insert(*lower.rbegin());
                lower.erase(--lower.end()); // DO NOT use lower.erase(lower.rbegin())
            }
            
            if (upper.size() > lower.size() + 1) {
                lower.insert(*upper.begin());
                upper.erase(upper.begin());
            }
            
            // push back median
            if (i >= k - 1) {
                if (k & 1) {
                    res.push_back(*upper.begin());
                } else {
                    res.push_back(((double)*upper.begin() + *lower.rbegin()) / 2);
                }
            }
        }
        return res;
    }
};