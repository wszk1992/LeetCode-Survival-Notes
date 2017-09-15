class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Solution1: HashMap, Space O(n) Time O(n)
        unordered_map<int, int> map;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(map.count(nums[i])) {
                res.push_back(map[nums[i]]);
                res.push_back(i);
                break;
            } else {
                map[target - nums[i]] = i;
            }
        }
        return res;
        
    }
};