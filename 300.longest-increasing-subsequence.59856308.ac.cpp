class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(nums[0]);
        int max_length = 1;
        for(int i = 1; i < nums.size(); i++){
            int len;
            for(len = max_length; len >= 1; len--){
                if(nums[i] > dp[len]){
                    if(len == max_length){
                        dp.push_back(nums[i]);
                        max_length++;
                    }
                    else {
                        dp[len+1] = nums[i];
                    }
                    break;
                }
            }
            if(len == 0){
                dp[1] = nums[i];
            }
        }
        
        return max_length;
    }
};