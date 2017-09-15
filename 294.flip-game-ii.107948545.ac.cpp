class Solution {
public:
    bool canWin(string s) {
        if(s.empty()) {
            return false;
        }
        int n = s.length();
        vector<bool> canFlip(n, true);
        for(int i = 0; i < s.length(); i++) {
            canFlip[i] = s[i] == '+';
        }
        return win(canFlip);
        
    }
    
    bool win(vector<bool>& canFlip) {
        for(int i = 0; i < canFlip.size() - 1; i++) {
            if(canFlip[i] && canFlip[i+1]) {
                canFlip[i] = false;
                canFlip[i+1] = false;
                if(!win(canFlip)) {
                    canFlip[i] = true;
                	canFlip[i+1] = true;
                    return true;
                }
                canFlip[i] = true;
                canFlip[i+1] = true;
            }
        }
        return false;
    }
    
};