class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while(j < k) {
                while(j < k && nums[j] + nums[k] >= target - nums[i]) {
                    k--;
                }
                count += k - j;
                j++;
            }
        }
        return count;
    }
};