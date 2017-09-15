class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) {
            return 0;
        }
        int res = 0;
        int num = 2;
        int d = A[1] - A[0];
        for(int i = 2; i < A.size(); i++) {
            if(A[i] - A[i-1] == d) {
                num++;
            }else {
                d = A[i] - A[i-1];
                num = 2;
            }
            if(num >= 3) {
                res += num - 2;
            }
        }
        return res;
    }
};