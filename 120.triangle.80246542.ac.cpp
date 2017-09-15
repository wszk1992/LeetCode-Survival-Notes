class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) {
            return 0;
        }
        int n = triangle.size();
        int minSum = INT_MAX;
        vector<int> sum(n, 0);
        sum[0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + triangle[i][i];
            for(int j = i - 1; j > 0; j--) {
                sum[j] = min(sum[j - 1], sum[j]) + triangle[i][j];
            }
            sum[0] = sum[0] + triangle[i][0];
        }
        for(int j = 0; j < n; j++) {
            minSum = min(minSum, sum[j]);
        }
        return minSum;
    }
};