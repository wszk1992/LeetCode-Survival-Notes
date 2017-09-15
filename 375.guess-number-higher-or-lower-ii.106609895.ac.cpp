class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        return topDown(dp, 0, n);
    }
    
    int topDown(vector<vector<int>>& dp, int start, int end) {
        if(dp[start][end] != INT_MAX) {
            return dp[start][end];
        }
        if(start == end) {
            return 0;
        }
        if(start == end - 1) {
            return start;
        }
        for(int i = start + 1; i < end; i++) {
            int money = i + max(topDown(dp, start, i - 1), topDown(dp, i + 1, end));
            dp[start][end] = min(dp[start][end], money);
        }
        return dp[start][end];
    }
};