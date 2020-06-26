// Description:
// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

// Note:
// 1. The length of both num1 and num2 is < 5100.
// 2. Both num1 and num2 contains only digits 0-9.
// 3. Both num1 and num2 does not contain any leading zero.
// 4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <string>
using std::string;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = 0;
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += (num2[j] - '0');
                j--;
            }
            sum += carry; 
            carry = sum / 10;
            sum %= 10;
            res += sum + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};