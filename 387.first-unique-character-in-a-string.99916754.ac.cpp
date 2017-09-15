class Solution {
public:
    int firstUniqChar(string s) {
        bitset<26> uniq;
        vector<int> dict(26, -1);
        for(int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            if(dict[index] == -1) {
                dict[index] = i;
                uniq[index] = 1;
            } else {
                uniq[index] = 0;
            }
        }
        if(uniq.count() == 0) {
            return -1;
        }
        int res = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(uniq[i]) {
                res = min(res, dict[i]);
            }
        }
        return res;
        
    }
};