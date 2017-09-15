class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> abbrs(1 << (target.length()));
        for(string word : dictionary) {
            if(word.length() != target.length()) continue;
            removeConflicts(abbrs, target, word, 0, 0);
        }
        // for(int a : abbrs) {
        //     cout << a << endl;
        // }
        int minLen = INT_MAX;
        string abbr;
        for(int i = 0; i < (1 << target.length()); i++) {
            int count = 0;
            if(abbrs[i] != -1) {
                pair<string, int> abbrPair = bitsToString(i, target);
                if(abbrPair.second < minLen) {
                    minLen = abbrPair.second;
                    abbr = abbrPair.first;
                }
            }
        }
        return abbr;
    }
    
    void removeConflicts(vector<int>& abbrs, string& target, string& word, int bits, int i) {
        if(i == target.length()) {
            abbrs[bits] = -1;
            return;
        }
        bits <<= 1;
        if(target[i] == word[i]) {
            removeConflicts(abbrs, target, word, bits, i + 1);
            removeConflicts(abbrs, target, word, bits | 1, i + 1);
        } else {
            removeConflicts(abbrs, target, word, bits | 1, i + 1);
        }
    }
    
    pair<string, int> bitsToString(int bits, string target) {
        string s;
        int len = target.length();
        int mask = 1 << (len-1);
        int count = 0;
        int size = 0;
        for(int i = 0; i < len; i++) {
            if(bits & mask) {
                count++;
            } else {
                if(count != 0) {
                    s += to_string(count);
                    size++;
                }
                s += target[i];
                size++;
                count = 0;
            }
            mask >>= 1;
        }
        if(count) {
            s += to_string(count);
            size++;
        }
        return make_pair(s, size);
        
    }
};