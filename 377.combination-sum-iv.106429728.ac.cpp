class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        return dfs(nums, dp, target);
    }
    
    int dfs(vector<int>& nums, unordered_map<int, int>& dp, int target) {
        if(dp.count(target)) {
            return dp[target];
        }
        if(target == 0) {
            return 1;
        }
        if(target < 0) {
            return 0;
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            count += dfs(nums, dp, target - nums[i]);
        }
        dp[target] = count;
        return count;
    }
};