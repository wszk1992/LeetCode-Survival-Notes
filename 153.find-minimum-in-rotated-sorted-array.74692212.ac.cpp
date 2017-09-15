class Solution {
public:
    int findMin(vector<int>& nums) {
        int front = 0;
        int end = nums.size() - 1;
        while(front < end) {
            int mid = front + (end - front) / 2;
            if(nums[mid] < nums[end]) {
                end = mid;
            }else if(nums[mid] > nums[end]) {
                front = mid + 1;
            }
        }
        return nums[front];
    }
};