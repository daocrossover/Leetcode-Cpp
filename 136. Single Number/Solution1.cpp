// Description:
// Given a non-empty array of integers, every element appears twice except for one.
// Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity.
// Could you implement it without using extra memory?

// Example 1:
// Input: [2,2,1]
// Output: 1

// Example 2:
// Input: [4,1,2,1,2]
// Output: 4


// Bit manipulation:
// a XOR a = 0, a XOR 0 = a
// a XOR a XOR b = 0 XOR b = b
// Time Complexity: O(n), Space Complexity: O(1)

#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        return res;
    }
};