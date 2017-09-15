class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int i = 0;
        while(i <= right) {
            if(nums[i] == 1) {
                i++;
            } else if(nums[i] == 0) {
                swap(nums[left++], nums[i++]);
            } else {
                swap(nums[right--], nums[i]);
            }
        }
    }
};