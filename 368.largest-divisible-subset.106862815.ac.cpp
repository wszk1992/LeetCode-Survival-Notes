class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // @@vector<int> factor = the index of one of the factors of the current element which has the largest subset
        // ##vector<int> len = the size of subset with the current element as the end.
        int maxLen = 0;
        int maxIndex = 0;
        vector<int> subset;
        if(nums.empty()) {
            return subset;
        }
        sort(nums.begin(), nums.end());
        vector<int> factor(nums.size(), -1);
        vector<int> len(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        factor[i] = j;
                    }
                }
            }
            if(len[i] > maxLen) {
                maxLen = len[i];
                maxIndex = i;
            }
        }
        while(maxIndex != -1) {
            subset.push_back(nums[maxIndex]);
            maxIndex = factor[maxIndex];
        }
        reverse(subset.begin(), subset.end());
        return subset;
    }
};