// Description:
// Design a HashSet without using any built-in hash table libraries.
// To be specific, your design should include these functions:

// add(value): Insert a value into the HashSet. 
// contains(value) : Return whether the value exists in the HashSet or not.
// remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

// Example:
// MyHashSet hashSet = new MyHashSet();
// hashSet.add(1);         
// hashSet.add(2);         
// hashSet.contains(1);    // returns true
// hashSet.contains(3);    // returns false (not found)
// hashSet.add(2);          
// hashSet.contains(2);    // returns true
// hashSet.remove(2);          
// hashSet.contains(2);    // returns false (already removed)

// Note:
// All values will be in the range of [0, 1000000].
// The number of operations will be in the range of [1, 10000].
// Please do not use the built-in HashSet library.

#include <vector>
using std::vector;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1000, vector<int>());
    }
    
    void add(int key) {
        int hash_key = key % 1000;
        if (data[hash_key].empty()) {
            data[hash_key].resize(1000);
        } 
        data[hash_key][key / 1000] = 1;
    }
    
    void remove(int key) {
        int hash_key = key % 1000;
        if (!data[hash_key].empty()) {
            data[hash_key][key / 1000] = 0;
        } 
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash_key = key % 1000;
        return !data[hash_key].empty() && data[hash_key][key / 1000];
    }

private:
    vector<vector<int>> data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */