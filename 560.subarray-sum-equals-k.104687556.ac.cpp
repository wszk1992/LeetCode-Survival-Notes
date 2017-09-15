class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum = 0;
        int count = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            cum += nums[i];
            if(map.count(cum - k)) {
                count += map[cum - k];
            }
            map[cum]++;
        }
        return count;
    }
};