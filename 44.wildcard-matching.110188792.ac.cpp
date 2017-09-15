class Solution {
public:
    bool isMatch(string s, string p) {
        int ss = -1, ps = -1;
        int si = 0, pi = 0;
        while(si < s.length()) {
            if(pi < p.length() && (p[pi] == s[si] || p[pi] == '?')) {
                pi++;
                si++;
            } else if(pi < p.length() && p[pi] == '*'){
                pi++;
                ps = pi;
                ss = si + 1;
            } else {
                if(ss == -1) {
                    return false;
                }
                pi = ps;
                si = ss;
                ss++;
            }
        }
        while(pi < p.length() && p[pi] == '*') pi++;
        return pi == p.length();
    }

};