// Using bitset and two pointers

#include <cstdint>
#include <bitset>
using std::bitset;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bit_set(n);
        for (int i = 0; i < 32 / 2; ++i) {
            bool tmp = bit_set[i];
            bit_set[i] = bit_set[bit_set.size() - 1 - i];
            bit_set[bit_set.size() - 1 - i] = tmp;
        }
        return (uint32_t) bit_set.to_ulong();
    }
};