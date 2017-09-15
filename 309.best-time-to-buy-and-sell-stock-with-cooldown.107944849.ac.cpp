class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }
        int n = prices.size();
        vector<vector<int>> profits(n, vector<int>(3, 0));
        profits[0][0] = -prices[0], profits[0][1] = INT_MIN, profits[0][2] = 0;
        for(int i = 1; i < n; i++) {
            profits[i][0] = max(profits[i-1][2] - prices[i], profits[i-1][0]);
            profits[i][1] = profits[i-1][0] + prices[i];
            profits[i][2] = max(profits[i-1][1], profits[i-1][2]);
        }
        return max(profits[n-1][1], profits[n-1][2]);
    }
};