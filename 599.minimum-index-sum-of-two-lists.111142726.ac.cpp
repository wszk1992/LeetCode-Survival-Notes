class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int leastIndexSum = INT_MAX;
        vector<string> commons;
        unordered_map<string, int> restToIndex;
        for(int i = 0; i < list1.size(); i++) {
            restToIndex[list1[i]] = i;
        }
        for(int i = 0; i < list2.size(); i++) {
            if(restToIndex.count(list2[i])) {
                int indexSum = i + restToIndex[list2[i]];
                if(indexSum < leastIndexSum) {
                    commons = vector<string>(1, list2[i]);
                    leastIndexSum = indexSum;
                } else if(indexSum == leastIndexSum) {
                    commons.push_back(list2[i]);
                }
            }
        }
        return commons;
    }
};