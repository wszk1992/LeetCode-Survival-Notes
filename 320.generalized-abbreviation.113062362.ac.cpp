class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> abbrs;
        int n = pow(2, word.length());
        for(int i = 0; i < n; i++) {
            abbrs.push_back(getAbbr(word, i));
        }
        return abbrs;
    }
    
    string getAbbr(string& word, int bits) {
        string abbr;
        int count = 0;
        int len = word.length();
        for(int i = 0; i < len; i++) {
            if(bits & 1) {
                count++;
            } else {
                if(count >= 1) abbr += to_string(count);
                abbr += word[i];
                count = 0;
            }
            bits >>= 1;
        }
        if(count >= 1) abbr += to_string(count);
        return abbr;
    }
};