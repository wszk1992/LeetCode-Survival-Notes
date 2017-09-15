class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for(string s : strs) {
            string sort_s = s;
            sort(sort_s.begin(), sort_s.end());
            if(m.count(sort_s)) {
                res[m[sort_s]].push_back(s);
            } else {
                m[sort_s] = res.size();
                res.push_back(vector<string>(1, s));
            }
        }
        return res;
    }
    
};