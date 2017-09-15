class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.length()) {
            return "0";
        }
        string res;
        for(int i = 0; i < num.length(); i++) {
            while(!res.empty() && k > 0 && num[i] < res.back()) {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        while(k--) {
            res.pop_back();
        }
        //remove leading zero
        int i = 0;
        while(res[i] == '0') {
            i++;
        }
        return res.substr(i).empty() ? "0" : res.substr(i);
    }
};