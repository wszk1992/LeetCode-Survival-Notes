class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        while(n) {
            weight += n & 1;
            n >>= 1;
        }
        return weight;
    }
};