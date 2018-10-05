// Use the formula: G(i) = i^ (i/2).
// i>>1 -> i/2
// 1<<n -> 2^n

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1<<n;
        vector<int> res;
        for (int i = 0; i < size; ++i) {
            res.push_back(i ^ i>>1);
        }
        return res;
    }
};