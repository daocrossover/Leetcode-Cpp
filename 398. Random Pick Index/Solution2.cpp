#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    unordered_map<int, vector<int>> hash;
public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); ++i) {
            hash[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> res(hash[target]);
        return res[rand() % res.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */