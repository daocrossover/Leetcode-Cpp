// Min-Heap Solution:
// For every numbers in nums1, its best partner (yields min sum) always starts from nums2[0] 
// since arrays are all sorted
// The priority queue stores [first_element, second_element, current_partner_index]
// And for a specific number in nums1, its next candidate should be 
// first_element + nums2[current_partner_index + 1], unless out of boundary for nums2.
// Time Complexity: O(klogk)

#include <vector>
#include <queue>
using std::vector;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n1 = nums1.size(), n2 = nums2.size();
        // lambda function creating min-heap for vector<int>
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[0] + a[1] > b[0] + b[1];
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        int idx1 = 0, idx2 = 0;
        for (int i = 0; i < std::min(k, n1); ++i) {
            pq.push(vector<int>{nums1[i], nums2[0], 0});
        }
        while (!pq.empty() && k > 0) {
            vector<int> cur = pq.top();
            pq.pop();
            res.push_back(vector<int>{cur[0], cur[1]});
            if (cur[2] < n2 - 1) {
                pq.push(vector<int>{cur[0], nums2[++cur[2]], cur[2]});
            }
            k--;
        }
        return res;
    }
};