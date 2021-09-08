// Based on the idea from 1017
// for each bit, convert to base -2

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int i = arr1.size() - 1, j = arr2.size() - 1;
        int carry = 0, r = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            if (i >= 0) carry += arr1[i--];
            if (j >= 0) carry += arr2[j--];
            r = carry % (-2);
            carry /= -2;
            if (r < 0) {
                r += 2;
                carry += 1;
            }
            res.push_back(r); // reverse the vector in the end
        }
        // remove the leading zeros
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};