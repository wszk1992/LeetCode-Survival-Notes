class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) {
            return 0;
        }
        int n = citations.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(n - m <= citations[m]) {
                r = m;
            }else {
                l = m + 1;
            }
        }
        return n - l <= citations[l] ? n - l : 0;
    }
};