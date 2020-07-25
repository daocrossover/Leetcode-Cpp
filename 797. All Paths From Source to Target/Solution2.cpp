// BFS Solution:

#include <vector>
#include <queue>
using std::vector;
using std::queue;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        queue<vector<int>> q;
        q.push(path);
        while (!q.empty()) {
            path = q.front();
            q.pop();
            int cur = path.back();
            if (cur == graph.size() - 1) {
                res.push_back(path);
            }
            for (int n: graph[cur]) {
                vector<int> new_path(path);
                new_path.push_back(n);
                q.push(new_path);
            }
        }
        return res;
    }
};