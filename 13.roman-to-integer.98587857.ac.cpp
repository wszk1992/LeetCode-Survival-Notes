class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i == s.length() - 1 || map(s[i]) >= map(s[i+1])) {
                res += map(s[i]);
            } else {
                res -= map(s[i]);
            }
        }
        return res;
    }
    
    int map(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};