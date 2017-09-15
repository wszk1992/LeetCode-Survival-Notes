class Solution {
public:
    int numWays(int n, int k) {
        //last two colors are different
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k * (k - 1);
        for(int i = 3; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
        }
        return dp[n] + dp[n-1];
    }

};