class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }else if(nums.size() == 1) {
            return nums[0];
        }else {
            return max(robRange(nums, 1, nums.size()), robRange(nums, 0, nums.size() - 1));
        }
    }
    
    int robRange(vector<int>& nums, int start, int end) {
        int include = 0, exclude = 0;
        for(int k = start; k < end; k++) {
            int i = include, e = exclude;
            include = e + nums[k];
            exclude = max(i, e);
        }
        return max(include, exclude);
    }
};