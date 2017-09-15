class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string addr;
        int num = 0;
        helper(res, addr, s, num, 0);
        return res;
    }
    
    void helper(vector<string>& res, string& addr, string& s, int& num, int k) {
        if(num == 3) {
            string sub = s.substr(k);
            if(isAddr(sub)) {
                res.push_back(addr + sub);
            }
            return;
        }
        for(int i = k; i < s.length(); i++) {
            if(isAddr(s.substr(k, i - k + 1))) {
                addr += s.substr(k, i - k + 1) + ".";
                num++;
                helper(res, addr, s, num, i + 1);
                num--;
                addr.erase(addr.end() - (i - k + 2), addr.end());
            }
        }
    }
    
    bool isAddr(string s) {
        if(s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) {
            return false;
        }
        return stoi(s) <= 255;
    }
};