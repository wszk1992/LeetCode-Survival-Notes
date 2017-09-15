class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int dis = 0;
        int n = nums.size();
        vector<int> count(31);
        for(int num : nums) {
            int i = 0;
            int mask = 1 << 30;
            while(mask) {
                if(num & mask) count[i]++;
                i++;
                mask >>= 1;
            }
        }
        for(int i = 0; i < 31; i++) {
            dis += count[i] * (n - count[i]);
        }
        return dis;
    }
};