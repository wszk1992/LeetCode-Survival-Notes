class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        return dfs(dp, n);
    }
    
    int dfs(vector<int>& dp, int k) {
        if(dp[k] != INT_MAX) {
            return dp[k];
        }
        int limit = sqrt(k);
        for(int i = limit; i >= 1; i--) {
            dp[k] = min(dp[k], 1 + dfs(dp, k - i * i));
        }
        return dp[k];
    }
};