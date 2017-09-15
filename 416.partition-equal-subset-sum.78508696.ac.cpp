class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if(sum % 2) {
            return false;
        }
        sum /= 2;
        //  findsum
        return findSum(nums, sum, 0);
        
    }
    
    bool findSum(vector<int>& nums, int sum, int k) {
        if(sum < 0) {
            return false;
        }else if(sum == 0) {
            return true;
        }
        for(int i = k; i < nums.size(); i++) {
            if(i == k || nums[i] != nums[i-1]) {
                if(findSum(nums, sum - nums[i], i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};