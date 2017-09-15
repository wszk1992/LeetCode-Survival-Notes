class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string s;
        long sum = 0;
        backTracking(res, s, num, target, sum, 0, 0);
        return res;
    }
    
    void backTracking(vector<string>& res, string& s, string& num, int& target, long& sum, long last, int k) {
        if(k == num.size()) {
            if(sum + last == target) {
                res.push_back(s);
            }
            return;
        }
        long cur = 0;
        for(int i = k; i < num.size(); i++) {
            if(num[k] == '0' && i == k + 1) {
                break;
            } 
            cur = cur * 10 + num[i] - '0';
            // +/-
            sum += last;
            s += (k == 0 ? "" : "+") + num.substr(k, i-k+1);
            backTracking(res, s, num, target, sum, cur, i + 1);
            s.erase(s.size() - num.substr(k, i-k+1).size() - (k != 0));
            if(k != 0) {
                s += "-" + num.substr(k, i-k+1);
                backTracking(res, s, num, target, sum, -cur, i + 1);
                s.erase(s.size() - num.substr(k, i-k+1).size() - 1);
            }
            sum -= last;
            // *
            if(k != 0) {
                s += "*" + num.substr(k, i-k+1);
                backTracking(res, s, num, target, sum, last * cur, i + 1);
                s.erase(s.size() - num.substr(k, i-k+1).size() - 1);
            }
        }
    }
};