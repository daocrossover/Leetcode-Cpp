// Description:
// There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
// Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops.
// If there is no such route, output -1.

// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 
// Constraints:
// 1. The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// 2. The size of flights will be in range [0, n * (n - 1) / 2].
// 3. The format of each flight will be (src, dst, price).
// 4. The price of each flight will be in the range [1, 10000].
// 5. k is in the range of [0, n - 1].
// 6. There will not be any duplicated flights or self cycles.

// BFS Solution:

#include<vector>
#include<unordered_map>
#include<queue>
using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::queue;
using std::min;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // build the graph
        unordered_map<int, vector<pair<int, int>>> graph;
        for (vector<int>& v: flights) {
            graph[v[0]].push_back(make_pair(v[1], v[2]));
        }
        // BFS using queue
        int cost = INT_MAX, cnt = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(src, 0));
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> cur = q.front();
                q.pop();
                if (cur.first == dst) {
                    cost = min(cost, cur.second);
                }
                for (pair<int, int>& neighbor: graph[cur.first]) {
                    int sum = cur.second + neighbor.second;
                    if (sum > cost) continue; // pruning
                    q.push({neighbor.first, sum});
                }
            }
            if (cnt++ > K) break; // over k stops, terminate
        }
        return cost == INT_MAX ? -1 : cost;
    }
};