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
using std::vector;

class Solution {
private:
    const int k = 1337;
    
    // problem 50: Pow(x, n)
    int modularPow(int a, int b) {
        a %= k;
        int res = 1;
        while (b != 0) {
            if (b % 2 != 0) {
                res = res * a % k;
            }
            a = a * a % k;
            b /= 2;
        }
        return res;
    }
    
public:
    int superPow(int a, vector<int>& b) {
        a %= k;
        int res = 1;
        for (int i = 0; i < b.size(); ++i) {
            res = modularPow(res, 10) * modularPow(a, b[i]) % k;
        }
        return res;
    }
};