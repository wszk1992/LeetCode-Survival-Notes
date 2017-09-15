class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x ^ y;
        int dis = 0;
        int mask = 1 << 30;
        while(mask) {
            if(XOR & mask) dis++;
            mask >>= 1;
        }
        return dis;
    }
};