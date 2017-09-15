class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> com;
        combineHelper(res, com, n, k, 1, 0);
        return res;
    }
    
    void combineHelper(vector<vector<int>>& res, vector<int>& com, int& n, int& k, int begin, int num) {
        if(num == k) {
            res.push_back(com);
            return;
        }
        for(int i = begin; i <= n; i++) {
            com.push_back(i);
            combineHelper(res, com, n, k, i + 1, num + 1);
            com.pop_back();
        }
    }
};