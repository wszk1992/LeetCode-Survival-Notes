class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        //find the longest circle size in the graph
        vector<bool> arrived(nums.size());
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(arrived[i]) {
                continue;
            }
            int len = 1;
            int p = nums[i];
            while(p != i) {
                arrived[p] = 1;
                p = nums[p];
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};