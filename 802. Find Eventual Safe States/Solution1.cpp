// Description:
// In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.
// If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

// Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.
// More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

// Which nodes are eventually safe?
// Return them as an array in sorted order.

// The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.
// The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

// Example:
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Here is a diagram of the above graph.

// Illustration of graph

// Note:
// graph will have length at most 10000.
// The number of edges in the graph will not exceed 32000.
// Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].

// Solution:
// The crux of the problem is whether you can reach a cycle from the node you start in.
// A cycle-finding DFS algorithm on each node individually.
// This is a classic "white-gray-black" DFS algorithm.
// We mark a node gray on entry, and black on exit.
// If we see a gray node during our DFS, it must be part of a cycle.

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N);
        vector<int> res;
        for (int i = 0; i < N; ++i)
            if (dfs(i, color, graph))
                res.push_back(i);
        return res;
    }

    // colors: WHITE 0, GRAY 1, BLACK 2;
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph) {
        if (color[node] > 0)
            // the node has been visited
            // if it is gray return false, else it is black, return true
            return color[node] == 2;

        color[node] = 1;
        for (int neighbor: graph[node]) {
            if (color[node] == 2)
                continue;
            if (color[neighbor] == 1 || !dfs(neighbor, color, graph))
                return false;
        }

        color[node] = 2;
        return true;
    }
};