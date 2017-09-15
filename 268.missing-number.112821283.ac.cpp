class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            miss ^= i ^ nums[i];
        }
        return miss;
    }
};