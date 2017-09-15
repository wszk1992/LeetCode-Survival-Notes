class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.length()+1, vector<bool>(s.length()+1));
        dp[0][0] = true;
        for(int ip = 0; ip < p.length(); ip++) {
            if(p[ip] == '*') {
                dp[ip+1][0] = dp[ip-1][0];
            } else {
                dp[ip+1][0] = false;
            }
        }
        for(int ip = 0; ip < p.length(); ip++) {
            for(int is = 0; is < s.length(); is++) {
                //dp[ip+1][is+1]
                if(p[ip] == '*') {
                    char pre = p[ip - 1];
                    int i = is;
                    while(i >= 0 && (s[i] == pre || pre == '.')) {
                        if(dp[ip-1][i+1]) {
                            dp[ip+1][is+1] = true;
                            break;
                        }
                        i--;
                    }
                    if(dp[ip-1][i+1]) {
                        dp[ip+1][is+1] = true;
                    }
                } else if(p[ip] == s[is] || p[ip] == '.') {
                    dp[ip+1][is+1] = dp[ip][is];
                } else {
                    dp[ip+1][is+1] = false;
                }
            }
        }
        return dp[p.length()][s.length()];
    }
};