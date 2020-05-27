// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that 
// will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
// Each letter in the magazine string can only be used once in your ransom note.

// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 
// Constraints:
// You may assume that both strings contain only lowercase letters.

// Hashmap (Lookup table) Solution:
// Time Complexity: O(m+n)
// Space Complexity: O(1)

#include<string>
using std::string;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for (char c: magazine) {
            count[c-'a']++;
        }
        for (char c: ransomNote) {
            if (count[c-'a'] <= 0) {
                return false;
            }
            count[c-'a']--;
        }
        return true;
    }
};