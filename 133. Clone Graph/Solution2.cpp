// BFS using hashmap and queue
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == NULL) return NULL;
        unordered_map<int, UndirectedGraphNode*> hash; // store visited nodes
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label); //new node for return
        hash.insert(make_pair(newNode->label, newNode)); // add first node to HashMap
        
        queue<UndirectedGraphNode*> q; // to store original nodes need to be visited
        q.push(node); // add first original node to queue

        while (!q.empty()) { // if more nodes need to be visited
            UndirectedGraphNode* n = q.front(); // search first node in the queue
            q.pop();
            for (UndirectedGraphNode* neighbor : n->neighbors) {
                if (!hash.count(neighbor->label)) { 
                    // add to map and queue if this node hasn't been searched before
                    hash.insert(make_pair(neighbor->label, new UndirectedGraphNode(neighbor->label)));
                    q.push(neighbor);
                }
                // add neighbor to new created nodes
                hash[n->label]->neighbors.push_back(hash[neighbor->label]);
            }
        }
        
        return newNode;
    }
};