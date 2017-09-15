class Solution {
public:
    double myPow(double x, int n) {
        return myPowPositive(x, n);
    }
    
    double myPowPositive(double x, long n) {
        if(x == 0) {
            return 0;
        } else if(x == 1) {
            return 1;
        } else if(x == -1) {
            return n % 2 ? -1 : 1;
        }
        double res = 1;
        double res_last = 1;
        if(n >= 0) {
            while(n--) {
                res *= x;
                if(res_last == res) {
                    break;
                }
                res_last = res;
            }
        } else {
            res = myPowPositive(1/x, -n);
        }
        return res;
    }
};