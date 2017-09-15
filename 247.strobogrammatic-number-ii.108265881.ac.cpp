class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        string left;
        string right;
        vector<string> str = {"00", "11", "88", "69", "96"};
        backTracking(res, left, right, str, n);
        return res;
    }
    
    void backTracking(vector<string>& res, string& left, string& right, vector<string>& str, int& n) {
        if(n - 2 * left.size() <= 1) {
            reverse(right.begin(), right.end());
            if(n - 2 * left.size() == 1) {
                for(int i = 0; i < 3; i++) {
                    left += str[i][0];
                    res.push_back(left + right);
                    left.pop_back();
                }
            } else {
                res.push_back(left + right);
            }
            reverse(right.begin(), right.end());
            return;
        }
        for(int i = 0; i < str.size(); i++) {
            if(left.size() == 0 && i == 0 && n != 1) {
                continue;
            }
            left += str[i][0];
            right += str[i][1];
            backTracking(res, left, right, str, n);
            left.pop_back();
            right.pop_back();
        }
    }
};