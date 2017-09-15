class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cmb;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(res, cmb, candidates, target, 0);
        return res;
    }
    
    void combinationSumHelper(vector<vector<int>>& res, vector<int>& cmb, vector<int>& candidates, int target, int k) {
        if(target == 0) {
            res.push_back(cmb);
            return;
        }
        for(int i = k; i < candidates.size() && candidates[i] <= target; i++) {
            if(i == k || candidates[i] != candidates[i - 1]) {
                cmb.push_back(candidates[i]);
                combinationSumHelper(res, cmb, candidates, target - candidates[i], i + 1);
                cmb.pop_back();
            }
        }
    }
};