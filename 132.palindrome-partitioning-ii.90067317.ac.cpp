class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n);
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            dp[i] = i;
            for(int j = 0; j <= i; j++) {
                if(s[j] == s[i] && (j + 1 > i - 1 || pal[j + 1][i - 1])) {
                    pal[j][i] = true;
                    dp[i] = j == 0 ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n - 1];
    }
    
};