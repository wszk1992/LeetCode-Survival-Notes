class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1) {
            return 0;
        }
        if(k >= prices.size() / 2) {
            int profit = 0;
            //transaction happens as much as possible
            for(int i = 1; i < prices.size(); i++) {
                if(prices[i] > prices[i-1]) {
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }
        vector<vector<int>> dp(k + 1, vector<int>(prices.size()));
        for(int kk = 1; kk <= k; kk++) {
            int maxP = max(-prices[0], -prices[1]);
            for(int i = 1; i < prices.size(); i++) {
                dp[kk][i] = max(dp[kk][i-1], prices[i] + maxP);
                maxP = max(maxP, dp[kk-1][i-1] - prices[i]);
            }
        }
        return dp[k][prices.size()-1];
    }
};