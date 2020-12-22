// Construct graph using HashMap
// Add visited array

#include <vector>
#include <unordered_map>
#include <queue>
using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::priority_queue;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<int> dist(N + 1, INT_MAX);
        vector<bool> visited(N + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        for (vector<int> edge: times) {
            graph[edge[0]].push_back(make_pair(edge[1], edge[2]));
        }
        pq.push(make_pair(0, K));
        dist[K] = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            if (visited[node]) continue;
            visited[node] = true;
            for (pair<int, int> edge: graph[node]) {
                int next = edge.first, time = edge.second;
                if (dist[node] + time < dist[next]) {
                    dist[next] = dist[node] + time;
                    pq.push(make_pair(dist[next], next));
                }
            }
        }
        int max_dist = 0;
        for (int i = 1; i < dist.size(); ++i) {
            max_dist = std::max(dist[i], max_dist);
        }
        return max_dist != INT_MAX ? max_dist : -1;
    }
};