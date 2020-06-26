// Description:
// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

// Example:
// Input: 13
// Output: 6 
// Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

class Solution {
public:
    int countDigitOne(int n) {
        return getCount(n, 1);
    }
    
private:
    int getCount(int num, int k) {
        // base: ones, tens, hundreds...
        // get how many k at each position
        // eg. num = 123, k = 1
        long base = 1;
        int sum = 0;
        int n = num;
        while (n != 0) {
            // when 1 is at ones, sum += 1 * 12
            sum += base * (n / 10);
            // ones is 3
            int cur = n % 10;
            if (cur == k) {
                sum += num % base + 1;
            } else if (cur > k) {
                sum += base;
            }
            base *= 10;
            n /= 10;
        }
        return sum;
    }

    int getCount0(int num) {
        int base = 1;
        int sum = 0;
        int n = num;
        while (n != 0) {
            sum += base * (n / 10 - 1);
            int cur = n % 10;
            if (cur == 0) {
                sum += num % base + 1;
            } else if (cur > 0) {
                sum += base;
            }
            base *= 10;
            n /= 10;
        }
        return sum;
    }
};