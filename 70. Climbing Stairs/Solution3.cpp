// Fibonacci Formula:
// Time Complexity: O(logn), pow method takes log(n) time.
// Space Complexity: O(1)

#include<cmath>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1+sqrt5)/2, n+1) - pow((1-sqrt5)/2, n+1);
        return (int)(fibn / sqrt5);
    }
};