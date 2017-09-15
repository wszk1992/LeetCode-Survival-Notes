class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string se;
        for(string s : sentence) {
            se += s + " ";
        }
        int len = se.length();
        int k = 0;
        for(int i = 0; i < rows; i++) {
            k += cols;
            if(se[k % len] == ' ') {
                k++;
            } else {
                while(k > 0 && se[(k - 1) % len] != ' ') {
                    k--;
                }
            }
        }
        return k / len;
    }
};