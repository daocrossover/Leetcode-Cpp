// Description:
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
// Return a deep copy of the list.

// The Linked List is represented in the input/output as a list of n nodes. 
// Each node is represented as a pair of [val, random_index] where:
// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

// Example 1:
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

// Example 2:
// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]

// Example 3:
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

// Example 4:
// Input: head = []
// Output: []
// Explanation: Given linked list is empty (null pointer), so return null.
 
// Constraints:
// 1. -10000 <= Node.val <= 10000
// 2. Node.random is null or pointing to a node in the linked list.
// 3. Number of Nodes will not exceed 1000.

// HashMap Solution:
// Time Complexity: O(2n) = O(n) (two pass)
// Space Complexity: O(2n) = O(n) (n -> hashmap + n -> copied list)

#include <unordered_map>
using std::unordered_map;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> m;
        Node* p = head;
        while (p) {
            m[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while (p) {
            m[p]->next = m[p->next];
            m[p]->random = m[p->random];
            p = p->next;
        }
        return m[head];
    }
};