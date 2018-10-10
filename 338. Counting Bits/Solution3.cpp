// An easy recurrence for this problem is f[i] = f[i / 2] + i % 2
// i / 2 -> i >> 1, i % 2 -> i & 1, bit manipulation is faster

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> f(num+1);
        for (int i = 1; i <= num; ++i) {
            f[i] = f[i >> 1] + (i & 1);
        }
        return f;
    }
};