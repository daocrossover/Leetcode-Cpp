// Description:
// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
// A gray code sequence must begin with 0.

// Example 1:
// Input: 2
// Output: [0,1,3,2]
// Explanation:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// For a given n, a gray code sequence may not be uniquely defined.
// For example, [0,2,3,1] is also a valid gray code sequence.
// 00 - 0
// 10 - 2
// 11 - 3
// 01 - 1

// Example 2:
// Input: 0
// Output: [0]
// Explanation: We define the gray code sequence to begin with 0.
//              A gray code sequence of n has size = 2^n, which for n = 0 the size is 2^0 = 1.
//              Therefore, for n = 0 the gray code sequence is [0].


// Solution:
// n = 0: 0
// n = 1: 0, 1
// n = 2: 00, 01, 11, 10  (0, 1, 3, 2)
// n = 3: 000, 001, 011, 010, 110, 111, 101, 100 (0, 1, 3, 2, 6, 7, 5, 4)
// n = i: the first half contains the gray code of n = i-1
//        the second half is the reverse of the first half and plus 2^(i-1)

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        if (n < 0) return gray;
        gray.push_back(0);
        int inc = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = gray.size() - 1; j >= 0; --j) 
                gray.push_back(gray[j] + inc);
            inc <<= 1;
        }
        return gray;
    }
};
        // Or: 1 << i -> 2^i
        // for (int i = 0; i < n; ++i) {
        //     for (int j = gray.size() - 1; j >= 0; --j) {
        //         gray.push_back(gray[j] | 1 << i);
        //     }
        // }