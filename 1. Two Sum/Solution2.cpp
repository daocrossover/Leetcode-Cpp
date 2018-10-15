// 2 pass Hashtable Solution:
// Time Complexity: O(n), Space Complexity: O(n)

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) hash[nums[i]] = i;
        for (int i = 0; i < nums.size(); ++i) {
            int rest = target - nums[i];
            if (hash.find(rest) != hash.end() && hash[rest] != i)
                return vector<int>{i, hash[rest]};
        }
        return vector<int>{-1, -1};
    }
};