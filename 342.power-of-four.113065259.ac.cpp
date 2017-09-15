class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        //count 0 and count 1
        int count[2] = {0, 0};
        while(num) {
            count[num & 1]++;
            num >>= 1;
        }
        return count[0] % 2 == 0 && count[1] == 1;
    }
};