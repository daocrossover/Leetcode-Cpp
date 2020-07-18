// Min-heap Solution:
// Time Complexity: O(nlog(k))
// Space Complexity: O(k)

#include <vector>
#include <unordered_map>
#include <queue>
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::greater;
using std::pair;
using std::make_pair;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums) {
            count[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;
        for (auto it = count.begin(); it != count.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};