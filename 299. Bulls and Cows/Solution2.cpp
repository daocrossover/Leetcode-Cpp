// one pass
#include<string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int countA = 0;
        int countB = 0;
        int numbers[10];
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) countA++;
            else {
                if (numbers[secret[i]-'0']++ < 0) countB++;
                if (numbers[guess[i]-'0']-- > 0) countB++;
            }
        }
        return to_string(countA) + "A" + to_string(countB) + "B";
    }
};