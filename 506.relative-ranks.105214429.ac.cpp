class Solution {
public:
    struct Cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        }
    };
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> rank;
        vector<string> res(nums.size(), "");
        for(int i = 0; i < nums.size(); i++) {
            rank.push_back(make_pair(i, nums[i]));
        }
        sort(rank.begin(), rank.end(), Cmp());
        for(int i = 0; i < rank.size(); i++) {
            res[rank[i].first] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal" : i == 2 ? "Bronze Medal" : to_string(i + 1);
        }
        return res;
    }
};