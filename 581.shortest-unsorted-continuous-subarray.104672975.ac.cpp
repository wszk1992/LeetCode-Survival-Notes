class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int minOfSub = INT_MAX, maxOfSub = INT_MIN;
        bool unsortedFromLeft = false, unsortedFromRight = false;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1]) {
                unsortedFromLeft = true;
            }
            if(unsortedFromLeft) {
                minOfSub = min(minOfSub, nums[i]);
            }
            
            if(nums[n-1-i] > nums[n-i]) {
                unsortedFromRight = true;
            }
            if(unsortedFromRight) {
                maxOfSub = max(maxOfSub, nums[n-1-i]);
            }
        }
        int left = 1, right = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > minOfSub) {
                left = i;
                break;
            }
        }
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] < maxOfSub) {
                right = i;
                break;
            }
        }
        return right - left + 1;
    }
};