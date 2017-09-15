class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(uint32_t i = 0; i < 16; i++) {
            uint32_t temp = n & (1 << i);
            uint32_t mr = 31 - i;
            if(n & (1 << mr)) {
                n |= 1 << i;
            } else {
                n &= ~(1 << i);
            }
            if(temp) {
                n |= 1 << mr;
            } else {
                n &= ~(1 << mr);
            }
        }
        return n;
    }   
};