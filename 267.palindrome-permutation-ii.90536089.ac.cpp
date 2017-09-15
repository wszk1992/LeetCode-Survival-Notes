class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        vector<int> v(256, 0);
        string halfStr;
        char single;
        int countOdd = 0;
        for(char c : s) {
            v[c]++;
        }
        for(int i = 0; i < 256; i++) {
            if(v[i] % 2) {
                countOdd++;
                single = i;
            }
            halfStr += string(v[i] / 2, i);
        }
        if(countOdd > 1) {
            return res;
        }
        if(halfStr.empty()) {
            res.push_back(string(1,single));
        } else {
            bt(res, halfStr, 0, single, countOdd);
        }

        return res;
    }
    
    void bt(vector<string>& res, string s, int k, char& single, int& countOdd) {
        if(k == s.size() - 1) {
            string temp(s);
            reverse(temp.begin(), temp.end());
            string perm = countOdd ? s + single + temp : s + temp;
            res.push_back(perm);
            return;
        }
        for(int i = k; i < s.size(); i++) {
            if(i == k || s[i] != s[k]) {
                swap(s[i], s[k]);
                bt(res, s, k + 1, single, countOdd);
            }
        }
    }
};