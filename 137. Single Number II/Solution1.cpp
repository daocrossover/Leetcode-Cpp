// Description:
// Given a non-empty array of integers, every element appears three times except for one,
// which appears exactly once. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity.
// Could you implement it without using extra memory?

// Example 1:
// Input: [2,2,3,2]
// Output: 3

// Example 2:
// Input: [0,1,0,1,0,1,99]
// Output: 99


#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            // sum: count of 1 on i-th bit
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 1;
            }
            // For all numbers appearing 3 times, every bit sum of their sum
            // will be the multiple of 3
            // The rest will be the unique number
            res |= (sum % 3) << i;
        }
        return res;
    }
};