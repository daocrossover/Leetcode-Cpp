#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], mx = res, mn = res;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                mx = max(mx * nums[i], nums[i]);
                mn = min(mn * nums[i], nums[i]);
            } else {
                int tmp = mx;
                mx = max(mn * nums[i], nums[i]);
                mn = min(tmp * nums[i], nums[i]);
            }
            res = max(res, mx);
        }
        return res;
    }
};