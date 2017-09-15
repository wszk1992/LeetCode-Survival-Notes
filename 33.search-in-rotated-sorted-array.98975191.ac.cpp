class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(nums[m] < nums[m + 1]) {
                if(nums[m] > nums[r]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            } else {
                l = m + 1;
                break;
            }
        }
        int pivot = l;
        
        l = 0;
        r = nums.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            int m_real = (m + pivot) % nums.size();
            if (nums[m_real] < target) {
                l = m + 1;
            } else if (nums[m_real] > target){
                r = m;
            } else {
                return m_real;
            }
        }
        return nums[(l + pivot) % nums.size()] == target ? (l + pivot) % nums.size() : -1;
    }
};