class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int k = 0;
        while(1) {
            if(strs[0].length() == k) break;
            for(int i = 1; i < strs.size(); i++) {
                if(strs[i].length() == k || strs[i][k] != strs[i-1][k]) {
                    return k == 0 ? "" : strs[0].substr(0, k);
                }
            }
            k++;
        }
        return k == 0 ? "" : strs[0].substr(0, k);
    }
};