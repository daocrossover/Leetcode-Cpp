// Description:
// Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
// Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

// Example 1:
// Input: "banana"
// Output: "ana"

// Example 2:
// Input: "abcd"
// Output: ""

// Note:
// 1. 2 <= S.length <= 10^5
// 2. S consists of lowercase English letters.

// Binary Search + Rabin-Karp Algorithm
// Rolling hash idea:
// "banana" -> [b,a,n,a,n,a] -> [1, 0, 13, 0, 13, 0] (we give every char a number)
// "ban" -> ((1 * 26) * 26) + 13 = 689
// "ana" -> "ban" + 'a' - 'b' = (689 * 26) + 0 - 26 * 26 * 26 * b = 338

#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    string longestDupSubstring(string S) {
        string res = "";
        power = vector<int>(S.length(), 1);
		// precompute all the pow(26, k) modulus prime
        for (int i = 1 ; i < S.length(); i++) {
            power[i] = (power[i - 1] * 26) % prime;
        }
        // binary search the length of the substring
        int low = 2, high = S.length() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            string tmp = validate(mid, S);
            if (tmp.length() == 0) {
                high = mid - 1;
            } else {
                if (tmp.length() > res.length()) {
                    res = tmp;
                }
                low = mid + 1;
            }
        }
        return res;
    }
    
private:
    int prime = 19260817; // large prime number
    vector<int> power;
    
    string validate(int len, string &str) {
        if (len == 0) return "";
        unordered_map<int, vector<int>> hash;
        long long cur = 0;
        for (int i = 0 ; i < len; ++i) {
            cur = ((cur * 26) % prime + (str[i] - 'a')) % prime;
        }
        hash[cur] = vector<int>(1, 0);
        for (int i = len ; i < str.length(); ++i) {
            // use long long to avoid overflow
            // minus could result in negative modular result, so need to add prime
            cur = ((cur - (long long) power[len - 1] * (str[i - len] - 'a')) % prime + prime) % prime;
            cur = (cur * 26 + (str[i] - 'a')) % prime;
            int start = i - len + 1;
            if (hash.find(cur) == hash.end()) {
                hash[cur] = vector<int>(1, start);
            } else {
                // may occur hash collision
                // need to check all candidates
                for (int it: hash[cur]) {
                    if (strcmp((str.substr(it, len)).data(), str.substr(start, len).data()) == 0) {
                        return str.substr(it, len);
                    }
                }
                hash[cur].push_back(start);
            }
        }
        return "";
    }
};
