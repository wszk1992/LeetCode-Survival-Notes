class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; i++) {
            int len = words[i].length();
            int h = 0;
            while(h < n && words[h].length() > i) {
                h++;
            }
            if(h != len) return false;
            for(int j = i; j < words[i].length(); j++) {
                if(words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};