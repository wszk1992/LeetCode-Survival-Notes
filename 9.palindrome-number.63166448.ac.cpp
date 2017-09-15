class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        }
        
        int rev_x = 0;
        while(x > rev_x) {
            rev_x = rev_x * 10 + x % 10;
            x /= 10;
        }
        
        return (x == rev_x) || (x == rev_x / 10);
    }

};
