class Solution {
public:
    string reverseStr(string s, int k) {

        int n = s.length();
        int count = (n - 1) / (2 * k);
        for(int i = 0; i <= count; i++) {
            reverse(s.begin() + i * 2 * k, min(s.end(), s.begin() + (i * 2 + 1) * k));
        }
        return s;
    }
};