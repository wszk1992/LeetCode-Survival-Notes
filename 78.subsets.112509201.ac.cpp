class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ss;
        vector<int> s;
        helper(ss, s, nums, 0);
        return ss;
    }
    
    void helper(vector<vector<int>>& ss, vector<int>& s, vector<int>& nums, int k) {
        if(k == nums.size()) {
            ss.push_back(s);
            return;
        }
        //select
        s.push_back(nums[k]);
        helper(ss, s, nums, k+1);
        s.pop_back();
        //not select
        helper(ss, s, nums, k+1);
    }
};