// 503. Next Greater Element II
// Description:
// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
// return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, 
// which means you could search circularly to find its next greater number. 
// If it doesn't exist, return -1 for this number.

// Example 1:
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

// Example 2:
// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

// Constraints:
// 1 <= nums.length <= 10^4
// -109 <= nums[i] <= 10^9

// Monotonic Stack Solution:
// The same as 496. Next Greater Element I
// Build a monotonic decreasing index stack, but iterate the array twice

#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s; // index stack
        for (int i = 0; i < 2 * n; ++i) {
            // loop the array twice using double length and modulo
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return res;
    }
};