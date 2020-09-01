// Using bit masking to generate all the combinations.
// string = "abc" and combinationLength = 2
// num bit_rep a b c
// 1   0 0 1   0 0 1
// 2   0 1 0   0 1 0
// 3   0 1 1   0 1 1  "ab" combinationLength == number of set bit
// 4   1 0 0   1 0 0
// 5   1 0 1   1 0 1  "ac"
// 6   1 1 0   1 1 0  "ab"
// 7   1 1 1   1 1 1

#include <string>
#include <set>
using std::string;
using std::set;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        st = generate(characters, combinationLength);
        it = st.begin();
    }
    
    string next() {
        return it == st.end() ? "" : *it++;
    }
    
    bool hasNext() {
        return it != st.end();
    }

private:
    set<string> st; // using set to ensure order
    set<string>::iterator it;
    
    set<string> generate(string s, int len) {
        int mask = 1 << s.length();
        set<string> hold;
        string cur = "";
        for (int no = 1; no < mask; ++no) {
            int num = no, i = 0;
            // construct sub using bit mask
            while (num) {
                if (num & 1) {
                    cur += s[i];
                }
                i++;
                num >>= 1;
            }
            if (cur.length() == len) {
                hold.insert(cur);
            }
            cur = "";
        }
        return hold;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */