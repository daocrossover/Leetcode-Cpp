// i-th Fibonacci Number.
// Fib(n) = Fib(n-1) + Fib(n-2)
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};