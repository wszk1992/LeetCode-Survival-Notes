class Solution {
    vector<int> num;
    int k;
public:
    Solution(vector<int> nums) {
        num = nums;
    }
    
    int pick(int target) {
        int res = -1;
        k = 0;
        for(int i = 0; i < num.size(); i++) {
            if(num[i] == target) {
                k++;
                if(rand() % k == 0) {
                    res = i;
                } 
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */