class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> perm;
        int n = s.length();
        for(int i = 0; i < n + 1; i++) {
            perm.push_back(i + 1);
        }
        int numOfD = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'D') {
                numOfD++;
            } else {
                reverse(perm.begin() + i - numOfD, perm.begin() + i + 1);
                numOfD = 0;
            }
        }
        reverse(perm.begin() + n - numOfD, perm.begin() + n + 1);
        return perm;
    }
};