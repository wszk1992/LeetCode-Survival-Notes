class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //binary search
        double l = -10000, r = 10000;
        while(r - l >= 0.00001) {
            double m = (l + r) / 2;
            if(isLarger(nums, k, m)) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    }
    
    bool isLarger(vector<int>& nums, int k, double m) {
        vector<double> cum(nums.size()+1);
        for(int i = 0; i < nums.size(); i++) {
            cum[i+1] += cum[i] + nums[i] - m;
        }
        double minCum = 0;
        for(int i = k; i < nums.size() + 1; i++) {
            minCum = min(minCum, cum[i-k]);
            if(cum[i] - minCum > 0) {
                return false;
            }
        }
        return true;
    }
};