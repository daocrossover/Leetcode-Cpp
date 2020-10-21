// 1012. Numbers With Repeated Digits
// Description:
// Given a positive integer N, return the number of positive integers less than or equal to N that have at least 1 repeated digit.

// Example 1:
// Input: 20
// Output: 1
// Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.

// Example 2:
// Input: 100
// Output: 10
// Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.

// Example 3:
// Input: 1000
// Output: 262

// Note:
// 1 <= N <= 10^9

// Math Solution:
// if N = 8765, digits = [8,7,6,6]
// step 1: count the number with digits < n
// XXX: 9 * 9 * 8
// XX: 9 * 9
// X: 9
// step 2: count the number with same prefix
// 1XXX ~ 7XXX: A(9, 3) each
// 80XX ~ 86XX: A(8, 2) each
// 870X ~ 875X: A(7, 1) each
// 8760 ~ 8765: A(6, 0) = 1 each
// if digits array has repeated number, it means we can't use this prefix
// therefore, just break the loop

#include <vector>
#include <unordered_set>
using std::vector;
using std::unordered_set;

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int res = 0; // number without repeated digit
        vector<int> digits; // transform N + 1 to vector
        for (int x = N + 1; x > 0; x /= 10) {
            digits.insert(digits.begin(), x % 10);
        }
        int n = digits.size();
        // count the number with digits < n
        for (int i = 1; i < n; ++i) {
            res += 9 * permutation(9, i - 1);
        }
        // count the number with same prefix
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            for (int j = i > 0 ? 0 : 1; j < digits[i]; ++j) {
                if (seen.find(j) == seen.end()) {
                    // remaing digit is n - i - 1
                    res += permutation(9 - i, n - i - 1);
                }
            }
            if (seen.find(digits[i]) != seen.end()) break;
            seen.insert(digits[i]);
        }
        return N - res; // the number with repeated digits is N - res
    }

private:
    // the number of permutations A(n, m) = n * (n - 1) * ... * (n - m + 1)
    int permutation(int n, int m) {
        int res = 1;
        for (int k = 1; k <= m; ++k) {
            res *= (n - k + 1);
        }
        return res;
    }
};