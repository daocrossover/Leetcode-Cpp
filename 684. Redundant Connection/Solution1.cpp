// Description:
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added.
// The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

// The resulting graph is given as a 2D-array of edges.
// Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

// Return an edge that can be removed so that the resulting graph is a tree of N nodes.
// If there are multiple answers, return the answer that occurs last in the given 2D-array.
// The answer edge [u, v] should be in the same format, with u < v.

// Example 1:
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given undirected graph will be like this:
//   1
//  / \
// 2 - 3

// Example 2:
// Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
// Output: [1,4]
// Explanation: The given undirected graph will be like this:
// 5 - 1 - 2
//     |   |
//     4 - 3

// Note:
// 1. The size of the input 2D-array will be between 3 and 1000.
// 2. Every integer represented in the 2D-array will be between 1 and N,
// where N is the size of the input array.

// Union-Find Solution:
// At the beginning, every node is in different group. Union Find -> make nodes connected.
// root[1] = 2 -> node 1 and node 2 is connected. root[2] = 3 -> node 2 and node 3 is connected.
// If we find an edge [1, 3], root[1] = 2 and root[2] = 3, which means node 1 and 3 is connected before
// Hence there is a cycle.

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(2000, -1);
        for (int i = 0; i < edges.size(); ++i) {
            int x = find(root, edges[i][0]);
            int y = find(root, edges[i][1]);
            if (x == y) return edges[i];
            root[x] = y;
        }
        return vector<int>(2, -1);
    }
    
    int find(vector<int>& root, int i) {
        while (root[i] != -1) {
            i = root[i];
        }
        return i;
    }
};