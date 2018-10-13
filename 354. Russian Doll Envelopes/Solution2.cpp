// Using lower_bound function:
// if we do not sort the sub-arrays (with the same width) in descending order,
// the LIS in the height is then invalid.
// Suppose the sub-arrays are also sorted in ascending order,
// the height in the same width will be appended in our LIS method, wrong result.
// Time Complexity: O(nlogn), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    // sort the heights in the same width in descending order
    static bool compare(const pair<int,int> &a, const pair<int,int> &b) { 
        return (a.first < b.first) || (a.first == b.first && a.second > b.second);
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), compare);
        // Longest Increasing Subsequence
        vector<int> res;
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(res.begin(), res.end(), envelopes[i].second);
            if (it == res.end()) res.push_back(envelopes[i].second);
            else *it = envelopes[i].second;
        }
        return res.size();
    }
};