class Solution {
public:
    string findContestMatch(int n) {
        return match(n, 1, 0);
    }
    
    string match(int& n, int i, int winbits) {
        if(i == n) {
            return to_string(winbits + 1);
        }
        return "(" + match(n, i << 1, winbits) + "," + match(n, i << 1, i * 2 - 1 - winbits) + ")";
    }
};