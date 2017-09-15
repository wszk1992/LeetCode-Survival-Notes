class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<vector<int>> boldAreas;
        unordered_set<string> set;
        int maxLen = 0;
        for(string bold : dict) {
            set.insert(bold);
            maxLen = max(maxLen, (int)bold.length());
        }
        for(int i = 0; i < s.length(); i++) {
            for(int j = boldAreas.empty() ? i : max(i, boldAreas.back()[1] + 1); j < min((int)s.length(), i + maxLen); j++) {
                if(set.count(s.substr(i, j - i + 1))) {
                    if(boldAreas.empty() || boldAreas.back()[1] + 1 < i) {
                        boldAreas.push_back({i, j});
                    } else {
                        boldAreas.back()[1] = max(boldAreas.back()[1], j);
                    }
                }
            }
        }
        return getBoldTag(boldAreas, s);
    }
    
    string getBoldTag(vector<vector<int>>& boldAreas, string& s) {
        string res;
        int k = 0;
        int i = 0;
        while(i < s.length()) {
            if(k != boldAreas.size() && i == boldAreas[k][0]) {
                res += "<b>";
            }
            res += s[i];
            if(k != boldAreas.size() && i == boldAreas[k][1]) {
                res += "</b>";
                k++;
            }
            i++;
        }
        return res;
    }
};