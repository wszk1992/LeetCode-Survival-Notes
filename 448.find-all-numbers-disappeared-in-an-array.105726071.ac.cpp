class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int next = nums[i] - 1;
            while(nums[next] != 0) {
                int cur = next;
                next = nums[cur] - 1;
                nums[cur] = 0;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};