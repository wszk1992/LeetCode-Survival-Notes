class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> abbrs(dict.size());
        unordered_map<string, vector<int>> abbrToWord;
        unordered_map<string, string> commonPrefix;
        vector<int> abbrIndex(dict.size(), -1);
        for(int i = 0; i < dict.size(); i++) {
            string abbr = dict[i].front() + to_string(dict[i].size()-2) + dict[i].back();
            if(abbr.size() >= dict[i].size()) {
                abbrs[i] = dict[i];
            } else {
                if(abbrToWord.count(abbr)) {
                    string newPrefix;
                    string prefix = commonPrefix[abbr];
                    int k = 0;
                    while(k < prefix.size() && prefix[k] == dict[i][k]) {
                        newPrefix += prefix[k++];
                    }
                    commonPrefix[abbr] = newPrefix;
                    queue<int> conflictWords;
                    for(int m = 0; m < abbrToWord[abbr].size(); m++) {
                        conflictWords.push(abbrToWord[abbr][m]);
                    }
                    while(!conflictWords.empty()) {
                        int n = conflictWords.size();
                        while(n--) {
                            int index = conflictWords.front();
                            conflictWords.pop();
                            if(dict[index][k] == dict[i][k]) {
                                conflictWords.push(index);
                            } else {
                                abbrIndex[index] = max(k, abbrIndex[index]);
                            }
                        }
                        k++;
                    }
                    abbrIndex[i] = max(k-1, abbrIndex[i]);
                    abbrToWord[abbr].push_back(i);
                } else {
                    abbrIndex[i] = 0;
                    abbrToWord[abbr].push_back(i);
                    commonPrefix[abbr] = dict[i];
                }
            }
        }
        for(int i = 0; i < abbrIndex.size(); i++) {
            if(abbrIndex[i] != -1) {
                string pre = dict[i].substr(0, abbrIndex[i] + 1);
                abbrs[i] = pre.size() < dict[i].size() - 2 ? pre + to_string(dict[i].size() - pre.size() - 1) + dict[i].back() : dict[i];
            }
        }
        return abbrs;
    }
};