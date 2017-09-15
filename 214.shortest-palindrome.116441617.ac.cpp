class Solution {
public:
    string shortestPalindrome(string s) {
        //convert the problem to finding longest palindromic substring starting from first index
        int n = s.length();
        for(int i = n; i >= 1; i--) {
            int left = i / 2 - (i % 2 == 0);
            int right = i / 2;
            while(left >= 0 && s[left] == s[right]) {
                left--;
                right++;
            }
            if(left < 0) {
                string tail = s.substr(right);
                reverse(tail.begin(), tail.end());
                return tail + s;
            }
        }
        return "";
    }
};