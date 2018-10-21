// Description:
// Implement pow(x, n), which calculates x raised to the power n (x^n).

// Example 1:
// Input: 2.00000, 10
// Output: 1024.00000

// Example 2:
// Input: 2.10000, 3
// Output: 9.26100

// Example 3:
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// Note:
// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]


// Recursive Solution:

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        // if using n = -n directly
        // when x = 2, n = INT_MIN, will cause overflow
        // so first t = n / 2;
        int t = n / 2;
        if (n < 0) {
            t = -t;
            x = 1 / x;
        }
        double res = myPow(x, t);
        return n % 2 == 0 ? res * res : x * res * res;
    }
};