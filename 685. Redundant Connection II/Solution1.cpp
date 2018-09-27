// Description:
// In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node,
// plus every node has exactly one parent, except for the root node which has no parents.

// The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added.
// The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

// The resulting graph is given as a 2D-array of edges.
// Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

// Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes.
// If there are multiple answers, return the answer that occurs last in the given 2D-array.

// Example 1: 
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given directed graph will be like this:
//   1
//  / \
// v   v
// 2-->3

// Example 2:
// Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
// Output: [4,1]
// Explanation: The given directed graph will be like this:
// 5 <- 1 -> 2
//      ^    |
//      |    v
//      4 <- 3



// Union-Find Solution:
// Situation 1: There is no cycle, but containing a node(node 3) with indegree of 2
// delete the edge([2, 3]) which makes the indegree of node 3 to be 2
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
//   1
//  / \
// v   v
// 2-->3

// Situation 2: There is a cycle, but not containing a node with indegree of 2
// delete the edge([4,1]) which contributes to the cycle
// Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
// Output: [4,1]
// 5 <- 1 -> 2
//      ^    |
//      |    v
//      4 <- 3

// Situation 3: There is a cycle and containing a node(node 1) with indegree of 2
// delete the edge([3,1]) which contributes to the cycle and makes the indegree of node 1 to be 2
// Input: [[1,2], [2,3], [3,1], [4,1]]
// Output: [3,1]
//      4
//     /
//    v
//    1
//  /  ^
// v    \
// 2 -->3

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // Using union-find to detect whether a G has a cycle
        vector<int> root(n+1), first, second;
        for (auto& edge : edges) {
            if (root[edge[1]] == 0) {
                root[edge[1]] = edge[0];
            } else {
                // when the indegree of node is 2, 
                // second: later added edge, first: former added edge
                first = {root[edge[1]], edge[1]};
                second = edge;
                edge[1] = 0;
            }
        }
        for (int i = 0; i <= n; ++i) root[i] = i;
        // find whether the graph has a cycle
        for (auto& edge : edges) {
            if (edge[1] == 0) continue;
            int x = getRoot(root, edge[0]), y = getRoot(root, edge[1]);
            // G has a cycle, but first is empty -> Situation 2 -> delete the edge
            // G has a cycle and first exits -> Situation 3 -> delete the first
            if (x == y) return first.empty() ? edge : first;
            root[x] = y;
        }
        // G does not have cycle -> Situation 1 -> delete the second
        return second;
    }
    
    int getRoot(vector<int>& root, int i) {
        while (i != root[i]) i = root[i];
        return i;
    }
};

