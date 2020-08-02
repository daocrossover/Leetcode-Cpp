// DFS, Black-Grey-White Cycle Detected Solution:
// White node set (0): not visited
// Grey node set (1): currently visited and nodes in the visiting path are all grey
// Black node set (2): already visited and there is no cycle among the nodes
// The node is black -> all children are visited and no cycle, and the children are all black
// But could Memory Limit Exceeded

#include <vector>
using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (vector<int> p: prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, graph, visited)) {
                return false;
            }
        }
        return true;
    }
    
    bool dfs(int node, vector<vector<int>> graph, vector<int>& visited) {
        if (visited[node] == 1) return false;
        if (visited[node] == 2) return true;
        visited[node] = 1;
        for (int i = 0; i < graph[node].size(); ++i) {
            if (!dfs(graph[node][i], graph, visited)) {
                return false;
            }
        }
        visited[node] = 2;
        return true;
    }
};