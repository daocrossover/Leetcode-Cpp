// 146. LRU Cache
// Description:
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
// If the number of keys exceeds the capacity from this operation, evict the least recently used key.

// The functions get and put must each run in O(1) average time complexity.

// Example 1:
// Input:
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output:
// [null, null, null, 1, null, -1, null, -1, 3, 4]
// Explanation:
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:
// 1 <= capacity <= 3000
// 0 <= key <= 10^4
// 0 <= value <= 10^5
// At most 2 * 10^5 calls will be made to get and put.

// Solution:
// LRU uses HashMap and doubly-linked list

#include <unordered_map>
using std::unordered_map;

class LRUCache {
    // doubly-linked list
    class Node {
    public:
        int key, value;
        Node *prev, *next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }
        Node() {
            key = 0;
            value = 0;
        }
    };
    
private:
    unordered_map<int, Node*> map;
    Node *head, *tail;
    int capacity, count;
    
    // add a node to the head of the linkedlist
    void add(Node* n) {
        Node *after = head->next;
        head->next = n;
        n->prev = head;
        n->next = after;
        after->prev = n;
    }

    // remove a node
    void remove(Node* n) {
        Node *before = n->prev;
        Node *after = n->next;
        before->next = after;
        after->prev = before;
    }
    
    // remove the current updated node and
    // add it to the head of the doubly-linked list
    void update(Node* n) {
        remove(n);
        add(n);
    }
    
public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        count = 0;
    }

    ~LRUCache() {
        unordered_map<int, Node*>::iterator it;
        for (it = map.begin(); it != map.end(); ++it) {
            delete it->second;
        }
        delete head;
        delete tail;
    }
    
    int get(int key) {
        Node *n = map[key];
        if (n == nullptr) {
            return -1;
        }
        update(n);
        return n->value;
    }
    
    void put(int key, int value) {
        Node *n = map[key];
        if (n == nullptr) {
            n = new Node(key, value);
            map[key] = n;
            add(n);
            count++;
        } else {
            n->value = value;
            update(n);
        }
        if (count > capacity) {
            Node *del = tail->prev;
            remove(del);
            map.erase(del->key);
            count--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */