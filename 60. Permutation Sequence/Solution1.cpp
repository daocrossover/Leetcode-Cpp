// Description:
// The set [1,2,3,...,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"

// Given n and k, return the kth permutation sequence.

// Note:
// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.

// Example 1:
// Input: n = 3, k = 3
// Output: "213"

// Example 2:
// Input: n = 4, k = 9
// Output: "2314"


// Find regularity in the Permutations: n = 4, k = 17
// 1234
// 1243
// 1324
// 1342
// 1423
// 1432
// 2134
// 2143
// 2314 
// 2341
// 2413
// 2431
// 3124
// 3142
// 3214
// 3241
// 3412	<--- k = 17
// 3421
// 4123
// 4132
// 4213
// 4231
// 4312
// 4321

// First, every number in the nums(1234) appears (n-1)! times in the first position
// (17-1) / (4-1)! = 2 -> the first number is 3
// Once the first position fixed, every number in the nums(124) appears (n-2)! times in the second position
// (17-1) % (4-1)! = 4 and 4 / (4-2)! = 2 -> the second number is 4
// ...

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        vector<int> f(n, 1);
        string res;
        // generate the num vector from 1 to n
        for (int i = 1; i <= n; ++i) num.push_back(i);
        // produce the factorial from 1! to (n-1)!
        for (int i = 1; i < n; ++i) f[i] = f[i-1] * i;
        // convert to 0-based to be better handled by division and mod
        k--;
        // use the above regularity
        for (int i = n; i >= 1; --i) {
            int j = k / f[i-1];
            k %= f[i-1];
            res += to_string(num[j]);
            // remember to delete the already used number
            num.erase(num.begin() + j);
        }
        return res;
    }
    
};
