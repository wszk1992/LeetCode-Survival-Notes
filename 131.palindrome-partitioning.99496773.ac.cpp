class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res_list;
        vector<string> res;
        backTracking(res_list, res, s, 0);
        return res_list;
    }
    
    void backTracking(vector<vector<string>>& res_list, vector<string>& res, string& s, int k) {
        if(k == s.size()) {
            res_list.push_back(res);
        }
        for(int i = k; i < s.size(); i++) {
            if(isPalindrome(s.substr(k, i-k+1))) {
                res.push_back(s.substr(k, i-k+1));
                backTracking(res_list, res, s, i+1);
                res.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int size = s.size();
        for(int i = 0; i < size / 2; i++) {
            if(s[i] != s[size-i-1]) {
                return false;
            }
        }
        return true;
    }
};