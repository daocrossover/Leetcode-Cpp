// 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
// Description:
// You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.
// You are allowed to choose exactly 1 element from each row to form an array. 
// Return the Kth smallest array sum among all possible arrays.

// Example 1:
// Input: mat = [[1,3,11],[2,4,6]], k = 5
// Output: 7
// Explanation: Choosing one element from each row, the first k smallest sum are:
// [1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.

// Example 2:
// Input: mat = [[1,3,11],[2,4,6]], k = 9
// Output: 17

// Example 3:
// Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
// Output: 9
// Explanation: Choosing one element from each row, the first k smallest sum are:
// [1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.

// Example 4:
// Input: mat = [[1,1,10],[2,2,9]], k = 7
// Output: 12

// Constraints:
// 1. m == mat.length
// 2. n == mat.length[i]
// 3. 1 <= m, n <= 40
// 4. 1 <= k <= min(200, n ^ m)
// 5. 1 <= mat[i][j] <= 5000
// 6. mat[i] is a non decreasing array.

// Based on the 373. Find K Pairs with Smallest Sums
// Starting from the first row as the nums1, second row as the nums2
// Then the result array will be used as the nums1
// Time Complexity: O(k * logk * m)

#include <vector>
#include <queue>
using std::vector;

class Solution {
public:
    vector<int> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
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
            res.push_back(cur[0] + cur[1]); // result is the sum array instead
            if (cur[2] < n2 - 1) {
                pq.push(vector<int>{cur[0], nums2[++cur[2]], cur[2]});
            }
            k--;
        }
        return res;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row = mat[0];
        for (int i = 1; i < mat.size(); i++) {
            row = kSmallestPairs(row, mat[i], k);
        }
        return row[k-1];
    }
};