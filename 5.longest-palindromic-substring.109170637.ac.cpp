class Solution {
public:
    string longestPalindrome(string s) {
        //1 center
        int center1 = 0;
        int len1 = 0;
        for(int i = 0; i < s.length(); i++) {
            int j = 0;
            while(i-1-j >= 0 && i+1+j < s.length() && s[i-1-j] == s[i+1+j]) {
                j++;
            }
            if(j * 2 + 1 > len1) {
                center1 = i;
                len1 = j * 2 + 1;
            }
        }
        //2 center
        int center2 = 0;
        int len2 = 0;
        for(int i = 1; i < s.length(); i++) {
            int j = 0;
            while(i-1-j >= 0 && i+j < s.length() && s[i-1-j] == s[i+j]) {
                j++;
            }
            if(j * 2 > len2) {
                center2 = i;
                len2 = j * 2;
            }
        }
        return len1 > len2 ? s.substr(center1 - len1 / 2, len1) : s.substr(center2 - len2 / 2, len2);
    }
};