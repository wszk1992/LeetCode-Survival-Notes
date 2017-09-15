class Solution {
public:
    Solution(vector<int> nums) {
        initNums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return initNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> sflNums(initNums);
        for(int i = 0; i < sflNums.size(); i++) {
            swap(sflNums[i], sflNums[i + rand() % (sflNums.size() - i)]);
        }
        return sflNums;
    }
private:
    vector<int> initNums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */