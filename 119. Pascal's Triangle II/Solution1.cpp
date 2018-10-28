// Description:
// Given a non-negative index k where k ≤ 33,
// return the kth index row of the Pascal's triangle.
// Note that the row index starts from 0.

// Example:
// Input: 3
// Output: [1,3,3,1]

// Follow up:
// Could you optimize your algorithm to use only O(k) extra space?

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i <= rowIndex; ++i) {
            res.insert(res.begin(), 1);
            for (int j = 1; j < i; ++j) {
                res[j] += res[j+1];
            }
        }
        return res;
    }
};