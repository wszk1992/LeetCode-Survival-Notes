class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSub(nums, 0, nums.size());
    }
    
    int maxSub(vector<int>& nums, int begin, int end) {
        if(end - begin == 1) {
            return nums[begin];
        }
        int mid = (begin + end) / 2;
        int left = maxSub(nums, begin, mid);
        int right = maxSub(nums, mid, end);
        int combine = maxFromRight(nums, begin, mid) + maxFromLeft(nums, mid, end);
        return max(max(left, right), combine);
    }
    int maxFromLeft(vector<int>& nums, int begin, int end) {
        int max = INT_MIN;
        int sum = 0;
        for(int i = begin; i < end; i++) {
            sum += nums[i];
            max = sum > max ? sum : max;
        }
        return max;
    }
    
    int maxFromRight(vector<int>& nums, int begin, int end) {
        int max = INT_MIN;
        int sum = 0;
        for(int i = end - 1; i >= begin; i--) {
            sum += nums[i];
            max = sum > max ? sum : max;
        }
        return max;
    }
};