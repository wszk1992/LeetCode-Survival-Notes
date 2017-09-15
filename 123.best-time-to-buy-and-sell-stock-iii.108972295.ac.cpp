class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //divided the problem into two little problems: maxprofit(two transactions) = max of (maxprofit(one) + maxprofit(one))
        int n = prices.size();
        if(n <= 1) {
            return 0;
        }
        vector<int> m1(n), m2(n);
        int lowestPrice = prices[0];
        int highestPrice = prices[n-1];
        for(int i = 1; i < n - 1; i++) {
            if(prices[i] <= lowestPrice) {
                lowestPrice = prices[i];
            }
            m1[i] = max(m1[i-1], prices[i] - lowestPrice);
            if(prices[n-1-i] >= highestPrice) {
                highestPrice = prices[n-1-i];
            }
            m2[n-1-i] = max(m2[n-i], highestPrice - prices[n-1-i]);
        }
        int profit = max(m1[n-2], prices[n-1] - lowestPrice);
        for(int i = 1; i < n - 1; i++) {
            // cout << m1[i] << "," << m2[i+1] << endl;
            profit = max(profit, m1[i] + m2[i+1]);
        }
        return profit;
    }
};