// 1514. Path with Maximum Probability
// Description:
// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge 
// connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
// Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

// Example 1:
// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
// Output: 0.25000
// Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

// Example 2:
// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
// Output: 0.30000

// Example 3:
// Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
// Output: 0.00000
// Explanation: There is no path between 0 and 2.

// Constraints:
// 2 <= n <= 10^4
// 0 <= start, end < n
// start != end
// 0 <= a, b < n
// a != b
// 0 <= succProb.length == edges.length <= 2*10^4
// 0 <= succProb[i] <= 1
// There is at most one edge between every two nodes.

// Dijkstra's Algorithm
// PriorityQueue Implementation
// Multiplying probabilities will result in precision errors. 
// So, take log probabilities to sum up numbers instead of multiplying them.
// max(p1 * p2 * ...) = max(log(p1 * p2 * ...)) = max(log(p1) + log(p2) + ...) 
// = min((-log(p1)) + (-log(p2)) + ...) 
// -log(p[i]) > 0, since 0 <= p[i] <= 1

#include <vector>
#include <queue>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::greater;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> graph;
        vector<double> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1);
        for (int i = 0; i < edges.size(); ++i) {
            // negating all log costs
            graph[edges[i][0]].push_back(make_pair(edges[i][1], -log(succProb[i])));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], -log(succProb[i])));
        }
        dist[start] = 0.0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push(make_pair(0.0, start));
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            if (node == end) {
                // find the end node, return directly
                return 1 / exp(dist[end]);
            }
            visited[node] = true;
            for (pair<int, double> edge: graph[node]) {
                int next = edge.first;
                double weight = edge.second;
                if (visited[next]) continue;
                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push(make_pair(dist[next], next));
                }
            }
        }
        return 0.0;
    }
};