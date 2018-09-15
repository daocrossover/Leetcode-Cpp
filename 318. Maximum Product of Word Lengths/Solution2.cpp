// bit manipulation

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wordBits;
        int size = words.size();
        int maxLen = 0;
        for (int i = 0; i < size; ++i) {
            int word = 0;
            for (char c : words[i])
                word |= 1 << (c - 'a');
            wordBits.push_back(word);
            
            for (int j = 0; j < i; ++j)
                if ((wordBits[j] & wordBits[i]) == 0 && words[i].length() * words[j].length() > maxLen)
                    maxLen = words[i].length() * words[j].length();
        }        
        return maxLen;
    }
};