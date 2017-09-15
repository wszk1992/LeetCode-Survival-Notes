class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s;
        // map.push_back("abc");
        // map.push_back("def");
        // map.push_back("ghi");
        // map.push_back("jkl");
        // map.push_back("mno");
        // map.push_back("pqrs");
        // map.push_back("tuv");
        // map.push_back("wxyz");
        if(digits.empty()) {
            return res;
        }
        letterCombinationsHelper(map, digits, res, s, 0);
        return res;
    }
    
    void letterCombinationsHelper(vector<string>& map, string& digits, vector<string>& res, string s, int n) {
        if(n == digits.size()) {
            res.push_back(s);
            return;
        }
        for(int i = 0; i < map[digits[n] - '2'].size(); i++) {
            s.push_back(map[digits[n] - '2'][i]);
            letterCombinationsHelper(map, digits, res, s, n+1);
            s.pop_back();
        }
    }
    
    
};