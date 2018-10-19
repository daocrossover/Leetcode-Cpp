// Description:
// Given two integers dividend and divisor, divide two integers without using multiplication,
// division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero.

// Example 1:
// Input: dividend = 10, divisor = 3
// Output: 3

// Example 2:
// Input: dividend = 7, divisor = -3
// Output: -2

// Note:
// 1. Both dividend and divisor will be 32-bit signed integers.
// 2. The divisor will never be 0.
// 3. Assume we are dealing with an environment which could only store integers
// within the 32-bit signed integer range: [−2^31,  2^31 − 1].
// For the purpose of this problem, assume that your function returns 2^31 − 1
// when the division result overflows.

// Bit Manipulation:
// shift the divisor to the left by 1 bit, until it is larger than dividend
// two cases may cause overflow:
// divisor = 0;
// dividend = INT_MIN and divisor = -1 (because abs(INT_MIN) = INT_MAX + 1).

#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long tmp = dvs, multiple = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                multiple <<= 1;
            }
            dvd -= tmp;
            res += multiple;
        }
        return sign > 0 ? res : -res;
    }
};