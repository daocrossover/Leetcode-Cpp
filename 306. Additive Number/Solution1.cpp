// Description:
// Additive number is a string whose digits can form additive sequence.

// A valid additive sequence should contain at least three numbers.
// Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

// Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
// Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

// Example 1:
// Input: "112358"
// Output: true 
// Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
//              1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

// Example 2:
// Input: "199100199"
// Output: true 
// Explanation: The additive sequence is: 1, 99, 100, 199. 
//              1 + 99 = 100, 99 + 100 = 199
// Follow up:
// How would you handle overflow for very large input integers?

// Recursive Solution:
// Generate the first and second of the sequence, check if the rest of the string match the sum recursively.
// i and j are length of the first and second number. i should in the range of [0, n/2]. The length of their sum should >= max(i,j)

#include<string>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i <= n / 2; ++i) {
            // numbers in the additive sequence cannot have leading zeros
            if (num[0] == '0' && i > 1) return false;
            string add1 = num.substr(0, i);
            for (int j = 1; max(j, i) <= n - i - j; ++j) {
                // numbers in the additive sequence cannot have leading zeros
                if (num[i] == '0' && j > 1) break;
                string add2 = num.substr(i, j);
                if (isValid(add1, add2, j+i, num)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isValid(string add1, string add2, int start, string num) {
        if (start == num.length()) return true;
        // function stoll(): convert string to long long
        string sum = to_string(stoll(add1) + stoll(add2));
        int sumLen = sum.length();
        if (num.substr(start, sumLen) != sum || start + sumLen > num.length()) {
            // add1 + add2 != sum or over the boundry -> return false
            return false;
        } else {
            // recursively check the rest string
            return isValid(add2, sum, start + sumLen, num);
        }
    }
};