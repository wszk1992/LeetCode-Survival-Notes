class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int i = n - 1;
        for(; i >= 0; i--) {
            if(n - i > citations[i]) {
                break;
            }
        }
        return n - i - 1;
    }
};