// DFS Solution:

#include<vector>
using std::vector;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1);
        vector<int> color_table(N + 1, 0);
        for (vector<int> &edge: dislikes) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 1; i <= N; ++i) {
            if (color_table[i] == 0 && !dfs(graph, color_table, i, 1)) {
                return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& color_table, int node, int color) {
        color_table[node] = color;
        for (int neighbor: graph[node]) {
            if (color_table[neighbor] == color) {
                return false;
            }
            if (color_table[neighbor] == 0 && !dfs(graph, color_table, neighbor, -color)) {
                return false;
            }
        }
        return true;
    }
};