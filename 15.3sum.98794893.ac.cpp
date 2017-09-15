class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res_list;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                int l = i + 1;
                int r = nums.size() - 1;
                while(l < r) {
                    if(nums[l] + nums[r] + nums[i] < 0) {
                        l++;
                    } else if(nums[l] + nums[r] + nums[i] > 0) {
                        r--;
                    } else {
                        vector<int> res;
                        res.push_back(nums[i]);
                        res.push_back(nums[l]);
                        res.push_back(nums[r]);
                        res_list.push_back(res);
                        while(l < r && nums[l] + nums[r] + nums[i] == 0) {
                            l++;
                        }
                    }
                }
            }
        }
        return res_list;
    }
};