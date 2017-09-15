class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int count = 0;
        while(n) {
            count += n & 1;
            n >>= 1;
        }
        return count == 1;
    }
};