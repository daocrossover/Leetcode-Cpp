// Description:
// Given the head of a graph, return a deep copy (clone) of the graph.
// Each node in the graph contains a label (int) and a list (List[UndirectedGraphNode]) of its neighbors.
// There is an edge between the given node and each of the nodes in its neighbors.

// OJ's undirected graph serialization (so you can understand error output):
// Nodes are labeled uniquely.
// We use '#' as a separator for each node, and ',' as a separator for node label and each neighbor of the node.
 
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
// The graph has a total of three nodes, and therefore contains three parts as separated by #.

// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 
// Visually, the graph looks like the following:
//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/

// Note: The information about the tree serialization is only meant so that you can understand error output if you get a wrong answer.
// You don't need to understand the serialization to solve the problem.

// DFS using hashmap
#include<vector>
#include<unordered_map>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    // use hashmap in order to avoid cycle in the graph
    unordered_map<int, UndirectedGraphNode*> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return dfs(node);
    }
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
        if (!node) return node;
        if (hash.count(node->label)) return hash[node->label];
        UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
        // add new UndirectedGraphNode into the hashmap
        hash.insert(make_pair(clone->label, clone));
        for (int i = 0; i < node->neighbors.size(); ++i) {
            // need to push_back the real copies of the neighbors instead of references
            clone->neighbors.push_back(dfs(node->neighbors[i]));
        }
        return clone;
    }
};

