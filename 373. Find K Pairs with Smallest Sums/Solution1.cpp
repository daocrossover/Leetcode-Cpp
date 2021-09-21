// 373. Find K Pairs with Smallest Sums
// Description:
// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
// Define a pair (u, v) which consists of one element from the first array and one element from the second array.
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

// Example 1:
// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

// Example 2:
// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

// Example 3:
// Input: nums1 = [1,2], nums2 = [3], k = 3
// Output: [[1,3],[2,3]]
// Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

// Constraints:
// 1. 1 <= nums1.length, nums2.length <= 10^5
// 2. -10^9 <= nums1[i], nums2[i] <= 10^9
// 3. nums1 and nums2 both are sorted in ascending order.
// 4. 1 <= k <= 1000

// Min heap with size k
// Time Complexity: O(m * n * k * logk)
// Time Limit Exceeded

#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::pair;
using std::make_pair;

class Solution {
    struct cmp {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            return a.first + a.second < b.first + b.second;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (q.size() < k) {
                    q.push(make_pair(nums1[i], nums2[j]));
                } else if (nums1[i] + nums2[j] < q.top().first + q.top().second) {
                    q.pop();
                    q.push(make_pair(nums1[i], nums2[j]));
                }
            }
        }
        while (!q.empty()) {
            res.push_back(vector<int>{q.top().first, q.top().second});
            q.pop();
        }
        return res;
    }
};