class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string word : wordDict) {
            dict.insert(word);
        }
        int n = s.length();
        vector<bool> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = 1;
                }
            }
        }
        return dp[n];
    }
};