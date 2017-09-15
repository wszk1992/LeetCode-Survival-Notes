class Solution {
public:
    struct Cmp {
        bool operator() (string s1, string s2) {
            return s1.length() != s2.length() ? s1.length() > s2.length() : s1 < s2;
        }
    };
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), Cmp());
        for(string sub : d) {
            if(isSubseq(s, sub)) {
                return sub;
            }
        }
        return "";
    }
    
    bool isSubseq(string& s, string& sub) {
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == sub[j]) {
                j++;
            }
            if(j == sub.length()) {
                return true;
            }
        }
        return false;
    }
};