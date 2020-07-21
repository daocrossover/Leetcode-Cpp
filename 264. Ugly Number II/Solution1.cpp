// Description:
// Write a program to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// Note:  
// 1 is typically treated as an ugly number.
// n does not exceed 1690.

// (1) 1×2, 2×2, 3×2, 4×2, 5×2, …
// (2) 1×3, 2×3, 3×3, 4×3, 5×3, …
// (3) 1×5, 2×5, 3×5, 4×5, 5×5, …
// Every subsequence is the ugly-sequence itself (1, 2, 3, 4, 5, …) multiply 2, 3, 5.
// Use similar merge method as merge sort, to get every ugly number from the three subsequence.
// Every step we choose the smallest one, and move one step after,including nums with same value.

#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            ugly[i] = min(min(2 * ugly[p2], 3 * ugly[p3]), 5 * ugly[p5]);
            if (ugly[i] == 2 * ugly[p2]) p2++;
            if (ugly[i] == 3 * ugly[p3]) p3++;
            if (ugly[i] == 5 * ugly[p5]) p5++;
        }
        return ugly[n-1];
    }
};