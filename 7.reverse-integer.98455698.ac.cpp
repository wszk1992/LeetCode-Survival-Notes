class Solution {
public:
    int reverse(int x) {
        long res = 0;
        int sign = 1;
        if(x < 0) {
            sign = -1;
            x = -x;
        }
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        res = sign * res;
        return sign * res > INT_MAX || sign * res < INT_MIN ? 0 : (int)res;
    }
};