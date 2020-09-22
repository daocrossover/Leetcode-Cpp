// Description:
// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
// Examples:
// [2,3,4] , the median is 3
// [2,3], the median is (2 + 3) / 2 = 2.5
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. 
// Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
// Window position                Median
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
// Therefore, return the median sliding window as [1,-1,-1,3,5,6].

// Note:
// You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
// Answers within 10^-5 of the actual value will be accepted as correct.

// Two Mulitiset Solution:
// Create two treeset (ordered), store left and right part of arrays (split by median)
// the size of upper is larger than that of lower but will not exceed 1
// when k = odd number, the median is the first element of upper
// when k = even number, the median is the average of the last element of lower and first element of upper

// Time Complexity: O(nlogk)
// TreeSet remove element O(logk), Priority Queue remove element O(k)
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
            while (upper.size() < lower.size()) {
                upper.insert(*lower.rbegin());
                lower.erase(--lower.end());
            }
            
            while (upper.size() > lower.size() + 1) {
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