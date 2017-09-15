class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) {
            return res;
        }
        pair<int, int> range;
        range.first = range.second = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1) {
                range.second++;
            } else {
                string r = to_string(range.first) + (range.first == range.second ? "" : "->" + to_string(range.second));
                res.push_back(r);
                range.first = range.second = nums[i];
            }
        }
        string r = to_string(range.first) + (range.first == range.second ? "" : "->" + to_string(range.second));
        res.push_back(r);
        return res;
    }
};