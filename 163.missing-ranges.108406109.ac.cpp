class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        long start = lower;
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            if(nums[i] != start) {
                int end = nums[i] - 1;
                string r = start == end ? to_string(start) : (to_string(start) + "->" + to_string(end));
                ranges.push_back(r);
            }
            start = (long)nums[i] + 1;
        }
        if(start <= upper) {
            string r = start == upper ? to_string(start) : (to_string(start) + "->" + to_string(upper));
            ranges.push_back(r);
        }
        return ranges;
    }
};