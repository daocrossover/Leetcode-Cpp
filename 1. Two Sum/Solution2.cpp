// 2 pass HashMap Solution:
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) hash[nums[i]] = i;
        for (int i = 0; i < nums.size(); ++i) {
            int remain = target - nums[i];
            if (hash.find(remain) != hash.end() && hash[remain] != i) {
                return vector<int>{i, hash[remain]};
            }
        }
        return vector<int>{-1, -1};
    }
};