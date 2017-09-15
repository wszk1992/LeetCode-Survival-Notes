class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        generateParenthesisHelper(n, 0, 0, res, s);
        return res;
    }
    
    void generateParenthesisHelper(int& n, int l, int r, vector<string>& res, string& s) {
        if(r == n) {
            res.push_back(s);
            return;
        }
        if(l < n) {
            s += '(';
            generateParenthesisHelper(n, l + 1, r, res, s);
            s.pop_back();
        }
        if(r < l) {
            s += ')';
            generateParenthesisHelper(n, l, r + 1, res, s);
            s.pop_back();
        }
    }
};