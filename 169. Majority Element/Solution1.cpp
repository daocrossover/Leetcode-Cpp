// 169. Majority Element
// Description:
// Given an array of size n, find the majority element. 
// The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:
// Input: [3,2,3]
// Output: 3

// Example 2:
// Input: [2,2,1,1,1,2,2]
// Output: 2

// Boyer-Moore Voting Algorithm:
// Time complexity: O(n)
// Space complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = 0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                m = num;
                count = 1;
            } else if (m == num) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        return m;
    }
};