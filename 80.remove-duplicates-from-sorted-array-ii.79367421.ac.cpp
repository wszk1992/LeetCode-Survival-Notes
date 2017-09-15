class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int i1 = 1, i2 = 1;
        int count = 1;
        while(i2 < nums.size()) {
            if(nums[i2] == nums[i2 - 1]) {
                count++;
            }else {
                count = 1;
            }
            if(count <= 2) {
                nums[i1++] = nums[i2++];
            }else {
                i2++;
            }
        }
        return i1;
    }
};