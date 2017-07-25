class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) {
            return false;
        }
        unordered_set<string> dict;
        for(string word : wordDict) {
            dict.insert(word);
        }
        vector<bool> dp(s.length());
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
    
 
};
