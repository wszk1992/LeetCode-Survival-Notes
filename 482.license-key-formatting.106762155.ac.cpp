class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string format;
        int count = 0;
        for(int i = S.length() - 1; i >= 0; i--) {
            if(S[i] == '-') {
                continue;
            }
            if(count == K) {
                format += '-';
                count = 0;
            }
            format += toupper(S[i]);
            count++;
        }
        reverse(format.begin(), format.end());
        return format;
    }
};