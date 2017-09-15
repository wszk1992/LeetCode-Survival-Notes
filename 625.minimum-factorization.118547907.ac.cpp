class Solution {
public:
    int smallestFactorization(int a) {
        if(a == 1) {
            return 1;
        }
        long bit = 1;
        int digit = 9;
        long res = 0;
        while(a > 1 && digit > 1) {
            if(a % digit == 0) {
                a /= digit;
                res += bit * digit;
                bit *= 10;
                if(res > INT_MAX) {
                    return 0;
                }
            } else {
                digit--;
            }
        }
        if(a > 1) {
            return 0;
        }
        return res;
    }
};