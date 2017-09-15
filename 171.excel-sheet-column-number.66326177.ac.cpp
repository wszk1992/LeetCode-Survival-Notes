class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        int i = 1;
        while(!s.empty()) {
            num += (s.back() - 'A' + 1) * i;
            i *= 26;
            s.pop_back();
        }
        return num;
    }
};