class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        helper(res, subset, nums, 0);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int k) {
        res.push_back(subset);
        for(int i = k; i < nums.size(); i++) {
            if(i == k || nums[i] != nums[i-1]) {
                subset.push_back(nums[i]);
                helper(res, subset, nums, i + 1);
                subset.pop_back();
            }
        }
    }
};