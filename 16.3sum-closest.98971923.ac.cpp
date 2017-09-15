class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // minDiff = sum - target
        int minDiff = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i - 1]) {
                int l = i + 1;
                int r = nums.size() - 1;
                while(l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum > target) {
                        r--;
                    } else if(sum < target) {
                        l++;
                    } else {
                        return target;
                    }
                    if(abs(minDiff) > abs(sum - target)) {
                        minDiff = sum - target;
                    }
                }
            }
        }
        return minDiff + target;
    }
};