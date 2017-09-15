class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i >= 1) {
            if(nums[i] > nums[i - 1]) {
                int j = i;
                while(j < nums.size() && nums[i - 1] < nums[j]) {
                    j++;
                }
                swap(nums[i - 1], nums[j - 1]);
                reverse(nums.begin() + i, nums.end());
                break;
            }
            i--;
        }
        if(i == 0) {
            reverse(nums.begin(), nums.end());
        }
    }
};


