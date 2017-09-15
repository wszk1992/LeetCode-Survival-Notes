class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0;
        int minPrice = INT_MAX;
        for(int price : prices) {
            if(price <= minPrice) {
                minPrice = price;
            } else {
                m = max(m, price - minPrice);
            }
        }
        return m;
    }
};