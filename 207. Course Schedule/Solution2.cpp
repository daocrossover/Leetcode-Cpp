// DFS, Black-Grey-White Cycle Detected Solution:
// But could Memory Limit Exceeded

#include<vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, graph, visited)) return false;
        }
        return true;
    }
    
    bool dfs(int node, vector<vector<int>> graph, vector<int>& visited) {
        if (visited[node] == 1) return false;
        if (visited[node] == 2) return true;
        visited[node] = 1;
        for (int i = 0; i < graph[node].size(); ++i) {
            if (!dfs(graph[node][i], graph, visited)) return false;
        }
        visited[node] = 2;
        return true;
    }
};