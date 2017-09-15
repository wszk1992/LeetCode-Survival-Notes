class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }
        int i = nums[0];
        int j = INT_MAX;
        for(int num : nums) {
            if(num <= i) {
                i = num;
            }else if(num <= j) {
                j = num;
            }else {
                return true;
            }
        }
        return false;
    }
};