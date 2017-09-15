class Solution {
public:
    struct Cmp {
        bool operator()(pair<int, char>& p1, pair<int, char>& p2) {
            return p1.first > p2.first;
        }
    };
    string frequencySort(string s) {
        string freq;
        vector<pair<int, char>> dict(256, pair<int, char>(0, ' '));
        for(auto c : s) {
            dict[c].first++;
            dict[c].second = c;
        }
        sort(dict.begin(), dict.end(), Cmp());
        for(auto p : dict) {
            if(p.first != 0) {
                freq += string(p.first, p.second);
            }
        }
        return freq;
    }
};