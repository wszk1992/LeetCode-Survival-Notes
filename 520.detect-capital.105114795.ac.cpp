class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.empty()) {
            return false;
        }
        if(word.length() == 1) {
            return true;
        }
        char cap = word[0];
        bool lower = islower(word[1]);
        for(int i = 2; i < word.length(); i++) {
            if((islower(word[i]) && !lower) || (!islower(word[i]) && lower)) {
                return false;
            }
        }
        return (islower(cap) && lower) || isupper(cap);
    }
};