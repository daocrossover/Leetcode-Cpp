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

#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            window.insert(nums[i]);
            if (i >= k - 1) {
                multiset<int>::iterator it = window.end();
                --it;
                res.push_back(*it);
            }
            if (window.size() == k) {
                multiset<int>::iterator it = window.find(nums[i - k + 1]);
                window.erase(it);
            }
        }
        return res;
    }
};