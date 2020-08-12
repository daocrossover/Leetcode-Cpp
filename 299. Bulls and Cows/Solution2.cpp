// One-pass Solution

#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    string getHint(string secret, string guess) {
        int countA = 0, countB = 0;
        int numbers[10];
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                // accurate match (same digit with same position)
                countA++;
            } else {
                // if prev part of guess has curr digit in secret
                if (numbers[secret[i] - '0']++ < 0) countB++;
                // if prev part of secret has curr digit in guess
                if (numbers[guess[i] - '0']-- > 0) countB++;
            }
        }
        return to_string(countA) + "A" + to_string(countB) + "B";
    }
};