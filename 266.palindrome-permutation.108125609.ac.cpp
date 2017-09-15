class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> dict(256, 0);
        int odd = 0;
        for(char c : s) {
            dict[c]++;
        }
        for(int i = 0; i < 256; i++) {
            if(dict[i] % 2) {
                odd++;
            }
        }
        return odd <= 1;
    }
};