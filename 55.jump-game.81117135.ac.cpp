class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) {
            return true;
        }
        int n = nums.size();
        int i = 0, jumpMax = 0;
        while(i <= jumpMax) {
            jumpMax = max(jumpMax, nums[i] + i);
            if(jumpMax >= n - 1) {
                return true;
            }
            i++;
        }
        return false;
    }
};