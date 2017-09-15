class Solution {
public:
    struct Cmp {
        bool operator() (string s1, string s2) {
            return s1.length() != s2.length() ? s1.length() > s2.length() : s1 < s2;
        }
    };
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), Cmp());
        vector<string> uniqstrs;
        unordered_map<int, int> indexFlag;
        uniqstrs.push_back(strs[0]);
        indexFlag[strs[0].length()] = 0;
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(strs[i] == strs[i-1]) {
                count++;
            } else {
                uniqstrs.push_back(strs[i]);
                if(strs[i].length() != strs[i-1].length()) {
                    indexFlag[strs[i].length()] = uniqstrs.size() - 1;
                }
                if(count == 1) {
                    int j = 0;
                    for(; j < indexFlag[strs[i-1].length()]; j++) {
                        if(isSubseq(uniqstrs[j], strs[i-1])) {
                            break;
                        }
                    }
                    if(j == indexFlag[strs[i-1].length()]) {
                        return strs[i-1].length();
                    }
                }
                count = 1;
            }
        }
        if(count == 1) {
            int j = 0;
            for(; j < indexFlag[strs[n-1].length()]; j++) {
                if(isSubseq(uniqstrs[j], strs[n-1])) {
                    break;
                }
            }
            if(j == indexFlag[strs[n-1].length()]) {
                return strs[n-1].length();
            }
        }
        return -1;
    }
    
    bool isSubseq(string& s, string& sub) {
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == sub[j]) {
                j++;
            }
            if(j == sub.length()) {
                return true;
            }
        }
        return false;
    }
};