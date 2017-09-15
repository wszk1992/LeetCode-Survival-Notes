class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int len = words[0].length();
        int windowSize = len * words.size();
        unordered_map<string, int> dict;
        for(string word : words) {
            dict[word]++;
        }
        for(int k = 0; k < len; k++) {
            unordered_set<string> count;
            unordered_map<string, int> arrived;
            int start = k;
            int i = start;
            while(i <= (int)s.length() - len && i - start < windowSize) {
                string word = s.substr(i, len);
                if(dict.count(word)) {
                    if(++arrived[word] >= dict[word]) {
                        count.insert(word);
                    }
                }
                i += len;
            }
            if(i - start != windowSize) break;
            if(count.size() == dict.size()) res.push_back(start);
            
            for(; i <= (int)s.length() - len; i += len) {
                //add head word
                string head = s.substr(i, len);
                if(dict.count(head)) {
                    if(++arrived[head] >= dict[head]) {
                        count.insert(head);
                    }
                }
                //remove tail word
                string tail = s.substr(start, len);
                if(arrived.count(tail)) {
                    if(--arrived[tail] < dict[tail]) {
                        count.erase(tail);
                    }
                }
                start += len;
                if(count.size() == dict.size()) res.push_back(start);
            }
        }
        return res;
    }
};