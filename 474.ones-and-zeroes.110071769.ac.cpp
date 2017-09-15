class Solution {
public:
    struct Cmp {
        bool operator()(string& s1, string& s2) {
            return s1.length() != s2.length() ? s1.length() < s2.length() : s1 < s2;
        }
    };
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        sort(strs.begin(), strs.end(), Cmp());
        vector<int> numOfZero;
        for(string s : strs) {
            numOfZero.push_back(count(s.begin(), s.end(), '0'));
        }
        int maxLen = 0;
        dfs(strs, numOfZero, m, n, 0, 0, maxLen);
        return maxLen;
    }
    
    void dfs(vector<string>& strs, vector<int>& numOfZero, int m, int n, int k, int formLen, int& maxLen) {
        if(maxLen >= formLen + strs.size() - k) {
            return;
        }
        maxLen = max(maxLen, formLen);
        for(int i = k; i < strs.size(); i++) {
            if(i == k || strs[i] != strs[i-1]) {
                int zeros = numOfZero[i], ones = strs[i].length() - zeros;
                if(m - zeros >= 0 && n - ones >= 0) {
                    dfs(strs, numOfZero, m - zeros, n - ones, i + 1, formLen + 1, maxLen);
                }
            }
        }
    }
};