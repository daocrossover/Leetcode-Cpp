// Solving the follow up:
// If we check each Sk in this way of Solution1,
// then it would be O(kn) time where k is the number of incoming S and n is the length of t.
// This is inefficient.
// use hashmap and binary search could solve this problem.
// Assume the average length of the incoming strings is m
// binary search: match a character with time complexity O(logn)
// Time Complexity: O(n + k * m * logn), Space Complexity: O(n)

// function upper_bound():(implemented using binary search)
// Returns an iterator pointing to the first element in the range [first,last)
// which compares greater than val.

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        //build a record the index of each char in t
        vector<vector<int>> record(26);
        //add indexs
        for(int i = 0; i < t.size(); i++) {
            record[t[i]-'a'].push_back(i);
        }
        //check if each char in s is in the legal place
        int index = -1;
        for(int i = 0; i < s.size(); i++) {
            auto iter = upper_bound(record[s[i]-'a'].begin(), record[s[i]-'a'].end(), index);
            if(iter == record[s[i]-'a'].end()) return false;
            index = *iter;
        }
        return true;
    }
};