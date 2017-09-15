//find first position nums[n] >= target
//binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int front = 0;
        int end = nums.size() - 1;
        while(front < end) {
            int mid = front + (end - front) / 2;
            if(nums[mid] > target) {
                end = mid;
            }else if(nums[mid] < target) {
                front = mid + 1;
            }else {
                return mid;
            }
        }
        return target > nums[front] ? front + 1 : front;
    }
};