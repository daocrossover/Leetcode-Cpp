// Solution 2: MinMax Heuristic
// Generally, we will get 0 matches from the secret word
// the possiblity that get 0 matched is: (25/26) ^ 6 = 79.03%
// As a result, the size of wordlist reduces slowly.
// Therefore, we want to guess the word with minimum words of 0 matches.
// If we compare each two words and count their matches, the complexity will be O(N^2)
// We can calculate a score of similarity for each word and guess the word with the highest score
// Score of each word: add the number of words that have the same chars in the same positions.
// We guess the word that overlaps with most others

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
        for (int i = 0, matches = 0; i < 10 && matches < 6; ++i) {
            // counts[i][j]: number of words with char j at index i
            vector<vector<int>> count(6, vector<int>(26, 0));
            for (string w : wordlist) {
                for (int i = 0; i < 6; ++i) {
                    count[i][w[i] - 'a']++;
                }
            }
            string guess = wordlist[0];
            int best = 0;
            for (string w: wordlist) {
                int score = 0;
                for (int i = 0; i < 6; ++i) {
                    score += count[i][w[i] - 'a']; // all words with same chars in same positions
                }
                if (score > best) {
                    guess = w;
                    best = score;
                }
            }
            // guess the word that overlaps with most others
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