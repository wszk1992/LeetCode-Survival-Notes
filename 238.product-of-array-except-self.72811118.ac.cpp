class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pre = 1;
        int rev = 1;
        vector<int> result(n, 1);
        for(int i = 1; i < n; i++) {
            result[i] *= pre * nums[i - 1];
            result[n - i - 1] *= rev * nums[n - i];
            pre *= nums[i - 1];
            rev *= nums[n - i];
        }
        return result;
    }
};