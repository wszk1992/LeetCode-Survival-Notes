class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int maxOnes = 0;
        for(int num : nums) {
            if(num == 1) {
                ones++;
            } else {
                ones = 0;
            }
            maxOnes = max(maxOnes, ones);
        }
        return maxOnes;
    }
};