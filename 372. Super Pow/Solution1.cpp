// Description:
// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

// Example 1:
// Input: a = 2, b = [3]
// Output: 8

// Example 2:
// Input: a = 2, b = [1,0]
// Output: 1024

// math solution:
// c mod m = (a ⋅ b) mod m
// c mod m = [(a mod m) ⋅ (b mod m)] mod m
// a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k

#include<vector>
using namespace std;

class Solution {
    const int base = 1337;
    int modularPow(int a, int exponent) {
        a %= base;
        int res = 1;
        for (int i = 0; i < exponent; ++i) {
            res = (res * a) % base;
        }
        return res;
    }
    
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return modularPow(superPow(a, b), 10) * modularPow(a, last_digit) % base;
    }
};