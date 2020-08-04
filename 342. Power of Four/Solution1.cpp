// Description:
// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

// Example 1:
// Input: 16
// Output: true

// Example 2:
// Input: 5
// Output: false

// Follow up: Could you solve it without loops/recursion?

// Solution1:
// (num & (num - 1)) == 0 -> power of two
// (num & 0x55555555) != 0 -> 1 is in the odd position -> power of four

// Solution2:
// (num - 1) % 3 == 0 <-> (4^n - 1) % 3 == 0
// proof:
// (1) 4^n - 1 = (2^n + 1) * (2^n - 1)
// (2) among any 3 consecutive numbers, there must be one that is a multiple of 3
// Therefore, among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n) cannot be the one, 
// so that either (2^n-1) or (2^n+1) must be a multiple of 3, and 4^n-1 must be a multiple of 3 as well.

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
        // return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};