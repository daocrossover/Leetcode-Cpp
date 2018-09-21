// Description:
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
// You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

// Example:
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
// Follow up:
// Could you solve it in linear time?

// multiset solution: the idea is from max-heap(size of k)
// but priority queue in C++ can't delete an element directly, so use multiset
// time comlexity: O((n-k+1)*logk), space comlexity: O(k)

#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        vector<int> res(nums.size() - k + 1);
        // construct heap of size k
        multiset<int> window(nums.begin(), nums.begin() + k);
        res[0] = *window.rbegin();
        for (int i = 1; i < nums.size() - k + 1; ++i) {
            // delete the element out of window
            multiset<int>::iterator it = window.find(nums[i-1]);
            window.erase(it);
            // add right side element
            window.insert(nums[i-1+k]);
            // push the max element in heap into res
            res[i] = *window.rbegin();
        }
        return res;
    }
};