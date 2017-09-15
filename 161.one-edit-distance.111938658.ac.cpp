class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.length() == t.length()) {
            int edit = 0;
            int i = 0;
            while(i < s.length()) {
                if(s[i] != t[i]) {
                    edit++;
                }
                i++;
            }
            return edit == 1;
        } else {
            int i = 0, j = 0;
            while(i < s.length() || j < t.length()) {
                if(i == s.length() || j == t.length() || s[i] != t[j]) {
                    if(abs(i - j) == 1) {
                        return false;
                    }
                    if(s.length() < t.length()) {
                        j++;
                    } else {
                        i++;
                    }
                } else {
                    i++;
                    j++;
                }
            }
            return true;
        }
    }
};