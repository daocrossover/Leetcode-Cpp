// Description:
// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.

// Example:
// Input: 2
// Output: 91 
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
//              excluding 11,22,33,44,55,66,77,88,99


// DP and Math Solution:
// Let f(n) = count of number with unique digits of length n.
// f(1) = 10
// f(2) = 9 * 9
// f(3) = f(2) * 8 = 9 * 9 * 8
// f(4) = f(3) * 7 = 9 * 9 * 8 * 7...
// ...
// f(10) = 9 * 9 * 8 * 7 * 6 * ... * 1
// f(11) = 0 = f(12) = f(13)... any number with length > 10 couldn't be unique digits number.
// The problem is asking for numbers from 0 to 10^n. Hence return f(1) + f(2) + .. + f(n)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // corner case!
        if (n == 0) return 1;
        int res = 10;
        int uniqueDigits = 9;
        int availableNumber = 9;
        while (n-- > 1 && availableNumber > 0) {
            uniqueDigits = uniqueDigits * availableNumber;
            res += uniqueDigits;
            availableNumber--;
        }
        return res;
    }
};