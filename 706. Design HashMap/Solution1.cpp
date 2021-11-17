// 706. Design HashMap
// Description:
// Design a HashMap without using any built-in hash table libraries.

// Implement the MyHashMap class:
// 1. MyHashMap() initializes the object with an empty map.
// 2. void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
// 3. int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// 4. void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 
// Example 1:
// Input:
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
// Output:
// [null, null, null, 1, -1, null, 1, null, -1]

// Explanation:
// MyHashMap myHashMap = new MyHashMap();
// myHashMap.put(1, 1); // The map is now [[1,1]]
// myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
// myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
// myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
// myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
// myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
// myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
// myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

// Constraints:
// 0 <= key, value <= 10^6
// At most 10^4 calls will be made to put, get, and remove.

// Vector + LinkedList Solution:
// follow-ups:
// 1. load factor
// 2. hashing function
// 3. growing

#include <vector>
using std::vector;

class MyHashMap {
public:
    MyHashMap() {
        // add a dummy node at the beginning of each bucket
        buckets = vector<ListNode*>(10000, new ListNode(-1, -1));
    }
    
    ~MyHashMap() {
        for (auto p : buckets) {
            delete p;
        }
    }
    
    void put(int key, int value) {
        ListNode* pre = find(key);
        if (pre->next) {
            pre->next->value = value;
        } else {
            pre->next = new ListNode(key, value);
        }
    }
    
    int get(int key) {
        ListNode* pre = find(key);
        if (pre && pre->next) {
            return pre->next->value;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* pre = find(key);
        if (pre && pre->next) {
            ListNode* tmp = pre->next;
            pre->next = pre->next->next;
            tmp->next = nullptr;
            delete tmp;
        }
    }

private:
    class ListNode {
    public:
        int key, value;
        ListNode* next;

        ListNode(int key, int val) : 
            key(key), value(val), next(nullptr)
        {}
    };
    
    vector<ListNode*> buckets;
    
    int index(int key) {
        return key % 10000;
    }
    
    ListNode* find(int key) {
        ListNode *cur = buckets[index(key)], *pre = nullptr;
        while (cur && cur->key != key) {
            pre = cur;
            cur = cur->next;
        }
        return pre;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */