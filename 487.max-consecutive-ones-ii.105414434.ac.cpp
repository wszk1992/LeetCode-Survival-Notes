class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0;
        int num = 0;
        int secNum = 0;
        int zeros = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                if(zeros == 0) {
                    secNum = num;
                    zeros++;
                    num++;
                } else {
                    num = num - secNum;
                    secNum = num - 1;
                    zeros = 1;
                }
            } else {
                num++;
            }
            maxNum = max(maxNum, num);
        }
        return maxNum;
    }
};