class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()) {
            return 0;
        }
        int n = costs.size(), k = costs[0].size();
        int lastMin1 = 0, lastMin2 = 0;
        int lastj1 = -1, lastj2 = -1;
        for(int i = 0; i < n; i++) {
            int curMin1 = INT_MAX, curMin2 = INT_MAX;
            int curj1 = 0, curj2 = 0;
            for(int j = 0; j < k; j++) {
                if(j == lastj1) {
                    costs[i][j] += lastMin2;
                } else {
                    costs[i][j] += lastMin1;
                }
                //find two minimum costs
                if(costs[i][j] <= curMin1) {
                    curMin2 = curMin1;
                    curj2 = curj1;
                    curMin1 = costs[i][j];
                    curj1 = j;
                } else if(costs[i][j] <= curMin2) {
                    curMin2 = costs[i][j];
                    curj2 = j;
                }
            }
            lastMin1 = curMin1;
            lastj1 = curj1;
            lastMin2 = curMin2;
            lastj2 = curj2;
        }
        
        //find minimum of costs[n-1]
        int minCost = INT_MAX;
        for(int j = 0; j < k; j++) {
            minCost = min(minCost, costs[n-1][j]);
        }
        return minCost;
    }
};