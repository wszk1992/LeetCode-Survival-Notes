class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        vector<long> sortedWindow;
        for(int i = 0; i < k; i++) {
            sortedWindow.push_back(nums[i]);
        }
        sort(sortedWindow.begin(), sortedWindow.end());
       if(k % 2) {
            res.push_back(sortedWindow[k/2]);
        } else {
            res.push_back(double(sortedWindow[k/2] + sortedWindow[k/2-1]) / 2);
        }
        for(int i = k; i < nums.size(); i++) {
            int found1 = find(sortedWindow, nums[i]);
            sortedWindow.insert(sortedWindow.begin() + found1, nums[i]);
            int found2 = find(sortedWindow, nums[i-k]);
            sortedWindow.erase(sortedWindow.begin() + found2);
            if(k % 2) {
                res.push_back(sortedWindow[k/2]);
            } else {
                res.push_back(double(sortedWindow[k/2] + sortedWindow[k/2-1]) / 2);
            }
        }
        return res;
    }
    
    int find(vector<long>& window, int e) {
        int l = 0, r = window.size();
        while(l < r) {
            int m = l + (r - l) / 2;
            if(window[m] < e) {
                l = m + 1;
            } else if(window[m] > e) {
                r = m;
            } else {
                return m;
            }
        }
        return l;
    }
};
