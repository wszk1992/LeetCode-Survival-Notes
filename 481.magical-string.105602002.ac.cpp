class Solution {
public:
    int magicalString(int n) {
        if(n == 0) {
            return 0;
        }
        string s = "122";
        int count = 1;
        int i = 2;
        while(s.size() < n) {
            char c = 3 - (s.back() - '0') + '0';
            s += string(s[i] - '0', c);
            count += c == '1' ? s[i] - '0' : 0;
            i++;
        }
        return s.size() > n ? count - (s.back() == '1') : count;
    }
};