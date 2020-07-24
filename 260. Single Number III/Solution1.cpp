// Description:
// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
// Find the two elements that appear only once.

// Example:
// Input:  [1,2,1,3,2,5]
// Output: [3,5]

// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity.
// Could you implement it using only constant space complexity?

// Bit manipulation: 
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1: get the XOR of the two numbers we need to find
        int diff = 0;
        for (int num: nums) {
            diff ^= num;
        }
        // Get its last set bit (rightmost 1)
        diff &= -diff; // or diff &= ~(diff - 1)

        // Pass 2: the set bit in the diff means the difference of two elements that appear only once.
        vector<int> res(2, 0); // this vector stores the two numbers we will return
        for (int num : nums) {
            if ((num & diff) == 0) { // the bit is not set
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
};