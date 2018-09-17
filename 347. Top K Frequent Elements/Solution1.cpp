// Description:
// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        unordered_map<int, int>::iterator it;
        for (it = hash.begin(); it != hash.end(); ++it) {
            pair<int, int> tmp = make_pair(it->second, it->first);
            q.push(tmp);
            if (q.size() > k) q.pop();
        }
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};