class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, int> map;
        vector<vector<string>> group;
        for(string s : strings) {
            string c_s = convert(s);
            if(map.count(c_s)) {
                group[map[c_s]].push_back(s);
            } else {
                map[c_s] = group.size();
                group.push_back(vector<string>(1, s));
            }
        }
        return group;
    }
    
    string convert(string s) {
        int num = 'z' - s[0];
        for(int i = 0; i < s.length(); i++) {
            s[i] = 'a' + (s[i] - 'a' + num) % 26;
        }
        return s;
    }
};