class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        //int curNum = nums[0];
        int len = 1;
        //status:  0 -- euqal, 1 -- up, 2 -- down
        int status = 0;
        for(int i = 1; i < nums.size(); i++) {
            int curStatus = nums[i] > nums[i-1] ? 1 : nums[i] == nums[i-1] ? 0 : 2;
            if(curStatus != 0 && curStatus != status) {
                len++;
                status = curStatus;
            }
        }
        return len;
    }
};