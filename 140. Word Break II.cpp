class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string word : wordDict) {
            dict.insert(word);
        }
        int n = s.length();
        vector<vector<int>> dp(n + 1);
        dp[n].push_back(n);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j <= n; j++) {
                if(!dp[j].empty() && dict.count(s.substr(i, j - i))) {
                    dp[i].push_back(j);
                }
            }
        }
        vector<string> res;
        string sentence;
        backTracking(res, dp, sentence, s, 0);
        return res;
    }
    
    void backTracking(vector<string>& res, vector<vector<int>>& dp, string& sentence, string& s, int k) {
        if(k == s.length()) {
            sentence.pop_back();
            res.push_back(sentence);
            sentence.push_back(' ');
            return;
        }
        for(int i = 0; i < dp[k].size(); i++) {
            string w = s.substr(k, dp[k][i] - k);
            sentence += w + " ";
            backTracking(res, dp, sentence, s, dp[k][i]);
            sentence.pop_back();
            sentence.erase(sentence.size() - w.size());
        }
    }
};
