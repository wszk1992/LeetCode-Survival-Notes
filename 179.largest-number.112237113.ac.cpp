class Solution {
    struct Cmp {
        bool operator()(string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) return "0";
        vector<string> ss;
        for(int num : nums) {
            ss.push_back(to_string(num));
        }
        sort(ss.begin(), ss.end(), Cmp());
        string res;
        for(string s : ss) {
            res += s;
        }
        return res[0] == '0' ? "0" : res;
    }
};