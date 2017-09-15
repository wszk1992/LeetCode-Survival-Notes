class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(!isVowel(s[i])) {
                i++;
                continue;
            }
            if(!isVowel(s[j])) {
                j--;
                continue;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
    
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i'|| c == 'o' || c == 'u';
    }
};