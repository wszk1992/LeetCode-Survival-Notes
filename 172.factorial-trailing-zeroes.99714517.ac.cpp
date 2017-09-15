class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int lastNum = 0;
        int num = 0;
        for(int i = 13; i >= 1; i--) {
            int num = n / pow(5, i) - lastNum;
            lastNum = n / pow(5, i);
            res += num * i;
        }
        return res;
    }
};