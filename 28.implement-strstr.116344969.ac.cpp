class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) {
            return 0;
        }
        int n = haystack.length();
        int len = needle.length();
        for(int i = 0; i < n - len + 1; i++) {
            int j;
            for(j = 0; j < len; j++) {
                if(haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if(j == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};