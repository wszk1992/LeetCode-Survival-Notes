class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty()) {
            return res;
        }
        deque<int> maxQ;
        for(int i = 0; i < nums.size(); i++) {
            while(!maxQ.empty() && nums[i] > maxQ.back()) {
                maxQ.pop_back();
            }
            maxQ.push_back(nums[i]);
            if(i >= k) {
                if(nums[i-k] == maxQ.front()) {
                    maxQ.pop_front();
                }
            }
            if(i >= k - 1) {
                res.push_back(maxQ.front());
            }
        }
        return res;
    }
};
