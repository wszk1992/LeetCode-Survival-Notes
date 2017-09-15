class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            int mid = (start + end) / 2;
            if(nums[mid] < target) {
                start = mid + 1;
            }else {
                end = mid;
            }
        }
        if(nums[start] == target) {
            res.push_back(start);
        }else {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        end = nums.size() - 1;
        while(start < end - 1) {
            int mid = (start + end) / 2;
            if(nums[mid] > target) {
                end = mid - 1;
            }else {
                start = mid;
            }
        }
        if(nums[end] != target) {
            end -= 1;
        }
        res.push_back(end);
        return res;
    }
};