class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.length();
        for(int i = 0; i < (n + 1) / 2; i++) {
            if(num[i] != rotate(num[n - i - 1])) {
                return false;
            }
        }
        return true;
    }
    
    char rotate(char c) {
        if(c >= '2' && c <= '5' || c == '7') {
            return '-';
        } else if(c == '6') {
            return '9';
        } else if(c == '9') {
            return '6';
        } else {
            return c;
        }
    }
};