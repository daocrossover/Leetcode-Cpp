// Backtracking Solution:

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int num = 0; // current code
        helper(res, n, num);
        return res;
    }

private:
    void helper(vector<int>& res, int n, int& num) {
        if (n == 0) {
            res.push_back(num);
            return;
        }
        helper(res, n - 1, num); // ignore the bit
        num ^= 1 << (n - 1); // invert the bit
        helper(res, n - 1, num);
    }
};