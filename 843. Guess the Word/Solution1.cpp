// 843. Guess the Word
// Description:
// This is an interactive problem.
// You are given an array of unique strings wordlist where wordlist[i] is 6 letters long, and one word in this list is chosen as secret.
// You may call Master.guess(word) to guess a word. The guessed word should have type string and must be from the original list with 6 lowercase letters.
// This function returns an integer type, representing the number of exact matches (value and position) of your guess to the secret word. 
// Also, if your guess is not in the given wordlist, it will return -1 instead.

// For each test case, you have exactly 10 guesses to guess the word. At the end of any number of calls, 
// if you have made 10 or fewer calls to Master.guess and at least one of these guesses was secret, then you pass the test case.

// Example 1:
// Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"], numguesses = 10
// Output: You guessed the secret word correctly.
// Explanation:
// master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
// master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
// master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
// master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
// master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
// We made 5 calls to master.guess and one of them was the secret, so we pass the test case.

// Example 2:
// Input: secret = "hamada", wordlist = ["hamada","khaled"], numguesses = 10
// Output: You guessed the secret word correctly.

// Constraints:
// 1. 1 <= wordlist.length <= 100
// 2. wordlist[i].length == 6
// 3. wordlist[i] consist of lowercase English letters.
// 4. All the strings of wordlist are unique.
// 5. secret exists in wordlist.
// 6. numguesses == 10

// Solution 1: Random Guess
// Intuition:
// Take a word from wordlist and guess it. Get the matches of this word
// Update our wordlist and keep only the same matches to our guess.
// The key point is, which word should we guess from all of the wordlist?
// (1) Always Guess the First One
// (2) Guess a random word
// But this method can not pass all the tests
// Time complexity O(N)
// Space complexity O(N)

#include <string>
#include <vector>
using std::string;
using std::vector;

// This is the Master's API interface.
// You should not implement it, or speculate about its implementation
class Master {
public:
    int guess(string word);
};

class Solution {
public:
    int match(string s1, string s2) {
        int res = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] == s2[i]) {
                res++;
            }
        }
        return res;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        for (int i = 0, matches = 0; i < 10 && matches < 6; ++i) {
            // string guess = wordlist[0];
            string guess = wordlist[rand() % n];
            matches = master.guess(guess);
            vector<string> wordlist2;
            for (string w : wordlist) {
                if (match(guess, w) == matches) {
                    wordlist2.push_back(w);
                }
            }
            wordlist = wordlist2;
        }
    }
};