// 1017. Convert to Base -2
// Description:
// Given an integer n, return a binary string representing its representation in base -2.
// Note that the returned string should not have leading zeros unless the string is "0".

// Example 1:
// Input: n = 2
// Output: "110"
// Explantion: (-2)^2 + (-2)^1 = 2

// Example 2:
// Input: n = 3
// Output: "111"
// Explantion: (-2)^2 + (-2)^1 + (-2)^0 = 3

// Example 3:
// Input: n = 4
// Output: "100"
// Explantion: (-2)2 = 4

// Constraints:
// 0 <= n <= 109

#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    string baseNeg2(int n) {
        string res = "";
        int r = 0;
        // The base −r expansion of a number can be found by repeated division by −r
        while (n != 0) {
            r = n % (-2);
            n /= -2;
            // In most language, the result of dividing a negative number by a negative number is rounded towards 0, 
            // usually leaving a negative remainder. Example: -3 / -2 = 1 and -3 % -2 = -1
            // a = (−r)c + d = (−r)c + d − r + r = (−r)(c + 1) + (d + r). Because |d| < r, (d + r) is the positive remainder.
            // Therefore, to get the correct result, we should add 1 and r to the quotient and remainder respectively.
            if (r < 0) {
                r += 2;
                n += 1;
            }
            res = to_string(r) + res;
        }
        return res == "" ? "0" : res;
    }
};