class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"qwertyuiop","asdfghjkl","zxcvbnm"};
        vector<int> charToRow(26);
        for(int i = 0; i < rows.size(); i++) {
            for(char c : rows[i]) {
                charToRow[c-'a'] = i;
            }
        }
        vector<string> res;
        for(string w : words) {
            int i;
            for(i = 1; i < w.length(); i++) {
                if(charToRow[tolower(w[i])-'a'] != charToRow[tolower(w[i-1])-'a']) {
                    break;
                }
            }
            if(i == w.length()) {
                res.push_back(w);
            }
        }
        return res;
    }
};