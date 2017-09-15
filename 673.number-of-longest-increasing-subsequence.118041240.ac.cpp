class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        vector<int> len(n);
        vector<int> count(n, 1);
        for(int i = 0; i < n; i++) {
            int maxLen = 0;
            int cnt = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(len[j] > maxLen) {
                        maxLen = len[j];
                        cnt = count[j];
                    } else if(len[j] == maxLen) {
                        cnt += count[j];
                    }
                }
            }
            len[i] = maxLen + 1;
            count[i] = cnt;
        }
        int maxLen = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(len[i] > maxLen) {
                maxLen = len[i];
                cnt = count[i];
            } else if(len[i] == maxLen) {
                cnt += count[i];
            }
        }
        return cnt;
    }
};