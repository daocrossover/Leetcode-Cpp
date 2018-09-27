// Description:
// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node,
// and w is the time it takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K.
// How long will it take for all nodes to receive the signal? If it is impossible, return -1.

// Note:
// N will be in the range [1, 100].
// K will be in the range [1, N].
// The length of times will be in the range [1, 6000].
// All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.

// Dijkstra's Algorithm:
// Using priority queue, time complexity O(mlogn)
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // N will be in the range [1, 100]
        vector<pair<int, int>> graph[N + 1];
        for (const auto& t : times) {
            graph[t[0]].push_back(make_pair(t[1], t[2]));
        }
        vector<int> d(N + 1, INT_MAX);
        d[K] = 0;
        // pair -> (d[n] (cost to the n from K), n (node n))
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0, K));
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            int u = cur.second;
            for (auto& neighbor : graph[u]) {
                int v = neighbor.first, w = neighbor.second;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pq.push(make_pair(d[v], v));
                }
            }
        }
        int res = *max_element(d.begin() + 1, d.end());
        return res == INT_MAX ? -1 : res;
    }
};