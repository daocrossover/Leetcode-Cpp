// Time Complexity: O(n), Space Complexity: O(1)

#include<vector>
using namespace std;

// the order is: prev2, prev1, num
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int num : nums) {
            int tmp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};