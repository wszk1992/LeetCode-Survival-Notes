class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, -1);
        for(int i = 1; i <= amount; i++) {
            int minNum = INT_MAX;
            for(auto coin : coins) {
                int k = i - coin;
                if(k == 0) {
                    minNum = 1;
                    break;
                }else if(k > 0 && dp[k] != -1) {
                    minNum = min(minNum, dp[k] + 1);
                }
            }
            dp[i] = minNum == INT_MAX ? -1 : minNum;
            //cout << dp[i] << endl;
        }
        return dp[amount];
    }
};