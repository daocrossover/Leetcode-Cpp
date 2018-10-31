// Greedy Solution:
// Time Complexity: O(nlogn), Space Complexity: O(1)

#include<vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end());
        int cur = pairs[0][1];
        int cnt = 1;
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > cur) {
                ++cnt;
                cur = pairs[i][1];
            } else {
                cur = min(cur, pairs[i][1]);
            }
        }
        return cnt;
    }

    static bool cmp (vector<int>& i, vector<int>& j) { 
        return i[1] < j[1]; 
    }
    // Consider the pairs in increasing order of their second coordinate.
    int findLongestChain1(vector<vector<int>>& pairs) {
        if (pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), cmp);
        int cur = INT_MIN;
        int res = 0;
        for (int i = 0; i < pairs.size(); ++i) {
            if (pairs[i][0] > cur) {
                res++;
                cur = pairs[i][1];
            }
        }
        return res;
    }
};