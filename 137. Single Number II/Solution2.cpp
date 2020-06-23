#include <vector>
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        // one: XOR of all the elements which have appeared "only" once
        // two: XOR of all the elements which have appeared "only" twice.
        for (int num: nums) {
            two |= one & num; // second time num has appeared, taken out of one (by XORing it again) and XORed into two
            one ^= num; // first time num has appeared, XORed into one
            three = one & two; // third time x has appeared, taken out of one and two
            one &= ~three; // reset one
            two &= ~three; // reset two
        }
        return one;
    }
};