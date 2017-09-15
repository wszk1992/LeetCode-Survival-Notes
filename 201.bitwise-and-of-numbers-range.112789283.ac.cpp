class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            int mm = (1 << i) & m;
            int nn = (1 << i) & n;
            if(mm ^ nn) {
                break;
            } else {
                res |= mm; 
            }
        }
        return res;
    }
};