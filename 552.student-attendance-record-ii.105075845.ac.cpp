class Solution {
public:
    int checkRecord(int n) {
        vector<int> dp(n + 1, 0);
        int mod = 1000000007;
        dp[0] = 1, dp[1] = 2, dp[2] = 4;
        for(int i = 3; i <= n; i++) {
            dp[i] = ((dp[i-3] + dp[i-2]) % mod + dp[i-1]) % mod;
        }
        int num = dp[n];
        for(int i = 0; i < n; i++) {
            num += (long(dp[i]) * dp[n - 1 - i]) % mod;
            num %= mod;
        }
        return num;
    }
};