class Solution {
public:
    void reverseWords(string &s) {
        bool countWord = 0;
        int begin = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++) {
            if(countWord == 0) {
                if(s[i] != ' ') {
                    begin = i;
                    countWord = 1;
                }
            } else {
                if(s[i] == ' ') {
                    end = i;
                    reverseWord(s, begin, end);
                    countWord = 0;
                }
            }
        }
        if(countWord) {
            reverseWord(s, begin, s.size());
        }
        reverseWord(s, 0, s.size());
        removeExtraSpaces(s);
    }
    
    void reverseWord(string& s, int begin, int end) {
        for(int i = 0; i < (begin + end) / 2 - begin; i++) {
            char temp = s[begin + i];
            s[begin + i] = s[end - 1 - i];
            s[end - 1 - i] = temp;
        }
    }
    
    void removeExtraSpaces(string& s) {
        int pos = 0;
        bool countWord = 0;
        for(int i = 0; i < s.size(); i++) {
            if(countWord) {
                if(s[i] == ' ') {
                    countWord = 0;
                }
                s[pos++] = s[i];
            } else {
                if(s[i] != ' ') {
                    s[pos++] = s[i];
                    countWord = 1;
                }
            }
        }
        s.erase(pos);
        if(s.back() == ' ') {
            s.pop_back();
        }
    }
};