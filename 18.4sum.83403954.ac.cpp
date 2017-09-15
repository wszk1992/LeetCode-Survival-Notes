class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if((i != 0 && nums[i] == nums[i-1])  || nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) {
                continue;
            }
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            for(int j = i + 1; j < nums.size(); j++) {
                if((j != i + 1 && nums[j] == nums[j-1]) || nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) {
                    continue;
                }
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }
                int remain = target - nums[i] - nums[j];
                int l = j + 1;
                int r = n - 1;
                while(l < r) {
                    if(nums[l] + nums[r] > remain) {
                        r--;
                    }else if(nums[l] + nums[r] < remain) {
                        l++;
                    }else {
                        vector<int> quad = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(quad);
                        while(l < r && nums[l] + nums[r] == remain) {
                            l++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

//-2 -1 0 0 1 2