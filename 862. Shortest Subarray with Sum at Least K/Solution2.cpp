// Pre-Sum + Priority Queue Solution:
// Sorting the presum in increasing order in order to use 
// sliding window idea for minimal length of window
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;
using std::pair;
using std::min;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX;
        long sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum >= k) {
                res = min(res, i + 1);
            }
            while (!pq.empty() && sum - pq.top().first >= k) {
                res = min(res, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return res == INT_MAX ? -1 : res;
    }
};