class Solution {
public:

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for(auto update : updates) {
            res[update[0]] += update[2];
            if(update[1] < length - 1) {
                res[update[1] + 1] -= update[2];
            }
        }
        int sum = 0;
        for(int i = 0; i < length; i++) {
            res[i] += sum;
            sum = res[i];
        }
        return res;
    }
};