// Design and implement a data structure for Least Recently Used (LRU) cache. 
// It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
// The cache is initialized with a positive capacity.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:
// LRUCache cache = new LRUCache( 2 /* capacity */ );
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

// LRU uses HashMap and doubly-linked list

#include<unordered_map>
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