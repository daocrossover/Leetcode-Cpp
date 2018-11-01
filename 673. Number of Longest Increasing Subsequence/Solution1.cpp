// Description:
// Given an unsorted array of integers, find the number of longest increasing subsequence.

// Example 1:
// Input: [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

// Example 2:
// Input: [2,2,2,2,2]
// Output: 5
// Explanation: The length of longest continuous increasing subsequence is 1,
// and there are 5 subsequences' length is 1, so output 5.

// Note: Length of the given array will be not exceed 2000
// and the answer is guaranteed to be fit in 32-bit signed int.


// Dynamic Programming Solution:
// len[i] = length of longest ending in nums[i]
// count[i] = number of longest ending in nums[i]
// For every i < j with A[i] < A[j], we might append A[j] to a longest subsequence
// ending at A[i].
// It means that we have demonstrated count[i] subsequences of length len[i] + 1.
// 1. Now, if those sequences are longer than len[j] (len[i] + 1 > len[j]),
// then we know we have count[i] sequences of this length.
// 2. If these sequences are equal in length to length[j],
// then we know that there are now count[i] additional sequences
// to be counted of that length (ie. count[j] += count[i]).

#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> count(n, 1);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (nums[i] < nums[j]) {
                    if (len[i] >= len[j]) {
                        len[j] = len[i] + 1;
                        count[j] = count[i];
                    } else if (len[i] + 1 == len[j]) {
                        count[j] += count[i];
                    }
                }
            }
        }
        // find the longest length
        int longest = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            longest = max(longest, len[i]);
        }
        // find the count of the longest sequence
        for (int i = 0; i < n; ++i) {
            if (len[i] == longest) {
                res += count[i];
            }
        }
        return res;
    }
};