class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int step = k % len;
        nums.insert(nums.end(), nums.begin(), nums.begin() + len - step);
        for(int i = 0; i < len; i++) {
            nums[i] = nums[i + len - step];
        }
        nums.erase(nums.begin() + len, nums.end());
    }
};