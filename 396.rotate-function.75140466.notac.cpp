class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.empty()) {
            return 0;
        }
        int n = A.size();
        int f_max = INT_MIN;
        for(int k = 0; k < n; k++) {
            f_max = max(f_max, F(k, A));
        }
        return f_max;
    }
    
    int F(int k, vector<int>& A) {
        int n = A.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int b = i + k < n ? i + k : i + k - n;
            res += i * A[b];
        }
        return res;
    }
};