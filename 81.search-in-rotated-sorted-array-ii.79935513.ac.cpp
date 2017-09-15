class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] > nums[end]) {
                if(target > nums[mid]) {
                    start = mid + 1;
                }else if(target >= nums[start]) {
                    end = mid;
                }else {
                    start = mid + 1;
                }
            }else if(nums[mid] < nums[end]) {
                if(target < nums[mid]) {
                    end = mid;
                }else if(target >= nums[start] && nums[start] >= nums[end]) {
                    end = mid;
                }else {
                    start = mid + 1;
                }
            }else {
                end--;
            }
        }
        return false;
    }
};