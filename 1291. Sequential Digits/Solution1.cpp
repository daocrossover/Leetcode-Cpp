// Description:
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

// Example 1:
// Input: low = 100, high = 300
// Output: [123,234]

// Example 2:
// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
 
// Constraints:
// 10 <= low <= high <= 10^9

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int a = digit_num(low), b = digit_num(high);
        while (a <= b) {
            for (int i = 1; i <= 10 - a; ++i) {
                int d = a - 1, cur = i, next_digit = i + 1;
                while (d > 0) {
                    cur = cur * 10 + next_digit;
                    next_digit++;
                    d--;
                }
                if (cur >= low && cur <= high) {
                    res.push_back(cur);
                }
            }
            a++;
        }
        return res;
    }

private:
    // get the number of digits
    int digit_num(int n) {
        int count = 0;
        while (n > 0) {
            n /= 10;
            count++;
        }
        return count;
    }
};