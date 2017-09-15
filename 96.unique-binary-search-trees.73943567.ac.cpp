class Solution {
public:
    int numTrees(int n) {
        if(n == 0) {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int mid = i / 2;
            for(int j = 0; j < mid; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
            dp[i] *= 2;
            if(2 * mid < i) {
                dp[i] += dp[mid] * dp[mid];
            }
        }
        return dp[n];
    }
    
};