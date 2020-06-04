// Description:
// Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.
// Here, a circular array means the end of the array connects to the beginning of the array.
// (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
// Also, a subarray may only include each element of the fixed buffer A at most once.
// (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

// Example 1:
// Input: [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3

// Example 2:
// Input: [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

// Example 3:
// Input: [3,-1,2,-1]
// Output: 4
// Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4

// Example 4:
// Input: [3,-2,2,-3]
// Output: 3
// Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3

// Example 5:
// Input: [-2,-3,-1]
// Output: -1
// Explanation: Subarray [-1] has maximum sum -1
 
// Note:
// 1. -30000 <= A[i] <= 30000
// 2. 1 <= A.length <= 30000

// Kadane's Algorithm Solution:
// 1. The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
// 2. The second is that the subarray take a part of head array and a part of tail array.
// case 2 could be transferred to the case 1: max(the max subarray sum, the total sum - the min subarray sum)

// Corner case: if all numbers are negative, maxSum = max(A) and minSum = sum(A).
// In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
// According to the description, We need to return the max(A), instead of sum of an empty subarray.
// So we return the maxSum to handle this corner case.

// Time Complexity: O(N)
// Space Complexity: O(1)

#include<vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int i = 0; i < A.size(); ++i) {
            curMax = max(curMax + A[i], A[i]);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + A[i], A[i]);
            minSum = min(minSum, curMin);
            total += A[i];
        }
        return maxSum < 0 ? maxSum : max(maxSum, total - minSum);
    }
};