class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        int i = 0;
        while(i < len - 1 - i) {
            char temp = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = temp;
            i++;
        }
        return s;
    }
};