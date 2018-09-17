// bucket sort
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> hash;
        for (auto num : nums) hash[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : hash) {
            bucket[kv.second].push_back(kv.first);
        }
        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};