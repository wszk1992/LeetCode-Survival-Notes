class Solution {
public:
    string decodeString(string s) {
        return decode(s, 0, s.length());
    }
    
    string decode(string& s, int start, int end) {
        string res;
        int k = 0;
        for(int i = start; i < end; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                k = k * 10 + s[i] - '0';
            } else if(s[i] == '[') {
                int index = findRightBracket(s, i);
                res += kString(decode(s, i + 1, index), k);
                i = index;
                k = 0;
            } else {
                res += s[i];
            }
        }
        return res;
    }
    
    int findRightBracket(string& s, int start) {
        int count = 0;
        for(int i = start; i < s.length(); i++) {
            if(s[i] == '[') {
                count++;
            } else if(s[i] == ']') {
                count--;
            }
            if(count == 0) {
                return i;
            }
        }
        return -1;
    }
    
    string kString(string s, int k) {
        string res;
        while(k--) {
            res += s;
        }
        return res;
    }
};