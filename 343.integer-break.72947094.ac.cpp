class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; i++) {
            for(int j = 1; 2 * j <= i; j++) {
                int a = max(dp[j], j);
                int b = max(dp[i - j], i - j);
                dp[i] = max(dp[i], a * b);
            }
        }
        return dp[n];
    }
};