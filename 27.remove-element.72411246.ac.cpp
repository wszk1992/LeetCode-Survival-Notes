class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) {
            return 0;
        }
        int i = 0;
        for(int num : nums) {
            if(num != val) {
                nums[i++] = num;
            }
        }
        return i;
    }
};