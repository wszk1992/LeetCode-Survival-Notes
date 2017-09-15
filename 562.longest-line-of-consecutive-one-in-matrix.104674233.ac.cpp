class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.empty() || M[0].empty()) {
            return 0;
        }
        int longestLine = 0;
        int m = M.size(), n = M[0].size();
        //left left-top top top-right
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(M[i][j]) {
                    dp[i][j][0] = j >= 1 ? dp[i][j-1][0] + 1 : 1;
                    dp[i][j][1] = i >= 1 && j >= 1 ? dp[i-1][j-1][1] + 1 : 1;
                    dp[i][j][2] = i >= 1 ? dp[i-1][j][2] + 1 : 1;
                    dp[i][j][3] = i >= 1 && j < n - 1 ? dp[i-1][j+1][3] + 1 : 1;
                    longestLine = max(longestLine, max(max(dp[i][j][0], dp[i][j][1]), max(dp[i][j][2], dp[i][j][3])));
                }
            }
        }
        return longestLine;
    }
};