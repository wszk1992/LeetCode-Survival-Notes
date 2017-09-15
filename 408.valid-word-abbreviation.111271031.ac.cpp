class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int num = 0;
        while(i < word.size() && j <= abbr.size()) {
            if(j == abbr.size() || (abbr[j] >= 'a' && abbr[j] <= 'z')) {
                i += num;
                if(j == abbr.size()) {
                    return i == word.size();
                }
                if(i >= word.size() || word[i] != abbr[j]) {
                    return false;
                }
                i++;
                j++;
                num = 0;
            } else {
                if(num == 0 && abbr[j] == '0') {
                    return false;
                }
                num = num * 10 + abbr[j++] - '0';
            }
        }
        return i == word.size() && j == abbr.size();
    }
};