class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        string res;
        int num = 1;
        for(int i = 1; i <= n; i++) {
            num *= i;
            s.push_back('0' + i);
        }
        k = k - 1;
        while(n) {
            num /= n;
            int cur = k / num;
            res.push_back(s[cur]);
            s.erase(s.begin() + cur);
            k %= num;
            n--;
        }
        return res;
    }
};