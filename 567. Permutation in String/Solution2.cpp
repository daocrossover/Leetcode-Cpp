// Two Hash Tables and Sliding Window Solution:

#include<string>
using std::string;

class Solution {
private:
    bool match(int s1_map[], int s2_map[]) {
        for (int i = 0; i < 26; ++i) {
            if (s1_map[i] != s2_map[i]) {
                return false;
            }
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2) return false;
        int s1_map[26] = {0}, s2_map[26] = {0};
        for (int i = 0; i < len1; ++i) {
            s1_map[s1[i] - 'a']++;
            s2_map[s2[i] - 'a']++;
        }
        for (int i = 0; i < len2 - len1; ++i) {
            if (match(s1_map, s2_map)) {
                return true;
            }
            s2_map[s2[i + len1] - 'a']++;
            s2_map[s2[i] - 'a']--;
        }
        return match(s1_map, s2_map);
    }
};