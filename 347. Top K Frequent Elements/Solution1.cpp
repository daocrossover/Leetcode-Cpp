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

// Max-heap Solution:
// Time Complexity: O(nlog(n-k))
// Space Complexity: O(n-k)

#include <vector>
#include <unordered_map>
#include <queue>
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::make_pair;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for (int num: nums) {
            count[num]++;
        }
        for (auto it = count.begin(); it != count.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > count.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};