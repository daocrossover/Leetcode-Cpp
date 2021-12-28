// Using upper_bound() to find the first number which is larger than x in the sum array

#include<vector>
using std::vector;

class Solution {
private:
    vector<int> prefix_sum;

public:
    Solution(vector<int>& w) {
        int s = 0;
        for (int weight: w) {
            s += weight;
            prefix_sum.push_back(s);
        }
    }
    
    int pickIndex() {
        int x = rand() % prefix_sum.back();
        return upper_bound(prefix_sum.begin(), prefix_sum.end(), x) - prefix_sum.begin();
    }
};