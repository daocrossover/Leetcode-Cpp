// DFS Solution:
// When add an edge, check whether there is a cycle. If we find a cycle, return current edge.
// Using adjacency list representation
// To avoid 1->{2}, 2->{1} dead loop, use pre to record last recursive node

#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> hash;
        for (auto edge : edges) {
            if (hasCycle(edge[0], edge[1], hash, -1)) return edge;
            hash[edge[0]].insert(edge[1]);
            hash[edge[1]].insert(edge[0]);
        }
        return {};
    }

    bool hasCycle(int cur, int target, unordered_map<int, unordered_set<int>>& hash, int pre) {
        if (hash[cur].count(target)) return true;
        for (int num : hash[cur]) {
            if (num == pre) continue;
            if (hasCycle(num, target, hash, cur)) return true;
        }
        return false;
    }
};