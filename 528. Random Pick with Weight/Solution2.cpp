// Using upper_bound() to find the first number which is larger than x in the sum array

#include<vector>
using std::vector;

class Solution {
private:
    vector<int> sum;

public:
    Solution(vector<int>& w) {
        int s = 0;
        for (int weight: w) {
            s += weight;
            sum.push_back(s);
        }
    }
    
    int pickIndex() {
        int x = rand() % sum.back();
        return upper_bound(sum.begin(), sum.end(), x) - sum.begin();
    }
};