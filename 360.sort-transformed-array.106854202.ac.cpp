class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        if(a == 0) {
            for(int x : nums) {
                res.push_back(b * x + c);
            }
            if(b < 0) {
                reverse(res.begin(), res.end());
            }
        } else {
            int mid = - b / (2 * a);
            vector<int> beforeMid, afterMid;
            for(int x : nums) {
                int y = a * x * x + b * x + c;
                if(x < mid) {
                    beforeMid.push_back(y);
                } else {
                    afterMid.push_back(y);
                }
            }
            if(a > 0) {
                reverse(beforeMid.begin(), beforeMid.end());
            } else {
                reverse(afterMid.begin(), afterMid.end());
            }
            res = mergeTwoVector(beforeMid, afterMid);
        }
        return res;
    }
    
    vector<int> mergeTwoVector(vector<int>& v1, vector<int>& v2) {
        vector<int> res;
        int i1 = 0, i2 = 0;
        while(i1 < v1.size() || i2 < v2.size()) {
            int val1 = i1 == v1.size() ? INT_MAX : v1[i1];
            int val2 = i2 == v2.size() ? INT_MAX : v2[i2];
            res.push_back(val1 < val2 ? v1[i1++] : v2[i2++]);
        }
        return res;
    }
};