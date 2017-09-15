class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wordsToInt(words.size());
        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                wordsToInt[i] |= 1 << (c - 'a');
            }
        }
        int maxPro = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                int w1 = wordsToInt[i];
                int w2 = wordsToInt[j];
                //take care of the operator precedence  (add brackets)
                if((w1 & w2) == 0) {
                    maxPro = max(maxPro, (int)words[i].length() * (int)words[j].length());
                }
            }
        }
        return maxPro;
    }
};