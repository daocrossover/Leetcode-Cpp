// Description:
// We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
// (Here, the distance between two points on a plane is the Euclidean distance.)
// You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

// Example 1:
// Input: points = [[1,3],[-2,2]], K = 1
// Output: [[-2,2]]
// Explanation: 
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

// Example 2:
// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
// Output: [[3,3],[-2,4]]
// (The answer [[-2,4],[3,3]] would also be accepted.)
 
// Note:
// 1. 1 <= K <= points.length <= 10000
// 2. -10000 < points[i][0] < 10000
// 3. -10000 < points[i][1] < 10000

// MaxHeap Solution:
// size K max heap
// Time Complexity: O(NlogK)
// Space Complexity: O(K)

#include<vector>
#include<queue>
using std::vector;
using std::pair;
using std::priority_queue;

class Solution {
public:
    int dist(vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> res;
        int distance = 0;
        for (int i = 0; i < points.size(); ++i) {
            distance = dist(points[i]);
            pq.push({distance, i});
            if (pq.size() > K) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};