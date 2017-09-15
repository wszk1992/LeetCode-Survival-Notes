class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int i1 = 0, i2 = 0;
        int minLen = INT_MAX;
        int curLen = 0;
        int sum = 0;
        while(i2 <= nums.size()) {
            if(sum >= s) {
                minLen = min(minLen, curLen);
                sum -= nums[i1++];
                curLen--;
            }else {
                if(i2 == nums.size()) {
                    break;
                }
                sum += nums[i2++];
                curLen++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};