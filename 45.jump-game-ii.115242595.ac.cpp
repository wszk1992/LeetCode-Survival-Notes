class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int step = 0;
        int start = 0;
        int jumpLimit = 0;
        while(jumpLimit < n - 1) {
            int nextLimit = jumpLimit;
            for(int i = start; i <= jumpLimit; i++) {
                nextLimit = max(nextLimit, i + nums[i]);
            }
            start = jumpLimit + 1;
            jumpLimit = nextLimit;
            step++;
        }
        return step;
    }
};