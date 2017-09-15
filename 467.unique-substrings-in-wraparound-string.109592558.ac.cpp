class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.empty()) {
            return 0;
        }
        int n = p.size();
        int count = 0;
        //max number of substring end with ('a' + index)
        vector<int> counts(26);
        int len;
        for(int i = 0; i < n; i++) {
            if(i != 0 && p[i] - 'a' == (p[i-1] + 1 - 'a') % 26) {
                len++;
            } else {
                len = 1;
            }
            counts[p[i]-'a'] = max(counts[p[i]-'a'], len);
        }
        for(int i = 0; i < 26; i++) {
            count += counts[i];
        }
        return count;
    }
};