class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int i1, i2;
        int newEle = nums[0];
        for(i1 = 0, i2 = 0; i2 < nums.size(); i2++) {
            if(nums[i2] != newEle) {
                nums[i1 + 1] = nums[i2];
                i1++;
                newEle = nums[i2];
            }
        }
        return i1 + 1;
    }
};