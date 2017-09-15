class Solution {
public:
    int longestPalindrome(string s) {
        int num = 0;
        bool hasMid = 0;
        vector<int> count(52, 0);
        for(char c : s) {
            int index = c >= 'a' && c <= 'z' ? c - 'a' : c - 'A' + 26;
            count[index]++;
        }
        for(int i = 0; i < 52; i++) {
            if(count[i] % 2 == 1) {
                num += hasMid ? count[i] - 1 : count[i];
                hasMid = true;
            } else {
                num += count[i];
            }
        }
        return num;
    }
};