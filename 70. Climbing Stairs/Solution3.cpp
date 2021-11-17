// Fibonacci Formula:
// Fn = (((1+sqrt(5))/2)^n - ((1-sqrt(5))/2)^n) / sqrt(5)
// Fibonacci begins with F(0)=0, F(1)=1, F(2)=1, F(3)=2
// but this problem begins with F'(1)=1, F'(2)=2
// we need n++ at the beginning to match the Fibonacci formula
// Time Complexity: O(logn), pow method takes log(n) time.
// Space Complexity: O(1)

#include <cmath>

class Solution {
public:
    int climbStairs(int n) {
        n++;
        double sqrt5 = sqrt(5);
        double fibn = pow((1+sqrt5)/2, n) - pow((1-sqrt5)/2, n);
        return (int)(fibn / sqrt5);
    }
};