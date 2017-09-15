class Solution {
public:
    int rob(vector<int>& nums) {
        int include = 0, exclude = 0;
        for(int k = 0; k < nums.size(); k++) {
            int i = include, e = exclude;
            include = e + nums[k];
            exclude = max(i, e);
        }
        return max(include, exclude);
    }
};