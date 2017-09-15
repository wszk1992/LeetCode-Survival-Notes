class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return winnerDiff(nums, 0, nums.size() - 1, dp) >= 0;
    }
    
    int winnerDiff(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if(start == end) {
            return nums[start];
        }
        if(dp[start+1][end] ==  -1) {
            dp[start+1][end] = winnerDiff(nums, start + 1, end, dp);
        }
        if(dp[start][end-1] == -1) {
            dp[start][end-1] = winnerDiff(nums, start, end - 1, dp);
        }
        return max(nums[start] - dp[start+1][end], nums[end] - dp[start][end-1]);
    }
};