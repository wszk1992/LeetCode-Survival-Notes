class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //pair: sum, num
        vector<pair<int, int>> lastSum(1, make_pair(0, 1));
        vector<pair<int, int>> curSum;
        for(int i = 0; i < nums.size(); i++) {
            //key: sum, value: index in curSum
            unordered_map<int, int> sumToIndex;
            for(int j = 0; j < lastSum.size(); j++) {
                vector<int> sums(2, 0);
                sums[0] = lastSum[j].first + nums[i], sums[1] = lastSum[j].first - nums[i];
                for(auto sum : sums) {
                    if(sumToIndex.count(sum)) {
                        curSum[sumToIndex[sum]].second += lastSum[j].second;
                    } else {
                        curSum.push_back(make_pair(sum, lastSum[j].second));
                        sumToIndex[sum] = curSum.size() - 1;
                    }
                }
            }
            if(i == nums.size() - 1) {
                return sumToIndex.count(S) ? curSum[sumToIndex[S]].second : 0;
            }
            lastSum = curSum;
            curSum = vector<pair<int, int>>();
        }
        return 0;
    }
};