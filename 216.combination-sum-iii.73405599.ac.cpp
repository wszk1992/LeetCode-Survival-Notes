class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cmb;
        combinationSum3Helper(res, cmb, k, n, 1);
        return res;
    }
    
    void combinationSum3Helper(vector<vector<int>>& res, vector<int>& cmb, int k, int n, int index) {
        if(k == 0) {
            if(n == 0) {
                res.push_back(cmb);
            }
            return;
        }
        if(n < 0) {
            return;
        }
        for(int i = index; i <= 9; i++) {
            cmb.push_back(i);
            combinationSum3Helper(res, cmb, k - 1, n - i, i + 1);
            cmb.pop_back();
        }
    }
};