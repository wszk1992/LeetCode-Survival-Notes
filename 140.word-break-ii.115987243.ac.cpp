class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string word : wordDict) {
            dict.insert(word);
        }
        int n = s.length();
        vector<vector<int>> dp(n+1);
        dp[0].push_back(0);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(!dp[j].empty() && dict.count(s.substr(j, i-j))) {
                    dp[i].push_back(j);
                }
            }
        }
        vector<string> res;
        vector<string> sentence;
        helper(res, sentence, s, dp, n);
        return res;
    }
    
    void helper(vector<string>& res, vector<string>& sentence, string& s, vector<vector<int>>& dp, int k) {
        if(k == 0) {
            reverse(sentence.begin(), sentence.end());
            string sent;
            for(string s : sentence) {
                sent += s + " ";
            }
            sent.pop_back();
            res.push_back(sent);
            reverse(sentence.begin(), sentence.end());
            return;
        }
        for(int i = 0; i < dp[k].size(); i++) {
            sentence.push_back(s.substr(dp[k][i], k - dp[k][i]));
            helper(res, sentence, s, dp, dp[k][i]);
            sentence.pop_back();
        }
    }
};