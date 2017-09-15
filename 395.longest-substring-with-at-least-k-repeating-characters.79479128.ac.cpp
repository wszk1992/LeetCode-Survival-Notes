class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(0, s.size(), s, k);
    }
    
    int helper(int start, int end, string& s, int& k) {
        if(start > end || end - start < k) {
            return 0;
        }
        vector<int> count(26, 0);
        for(int i = start; i < end; i++) {
            count[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] == 0) {
                continue;
            }
            if(count[i] < k) {
                for(int j = start; j < end; j++) {
                    if(s[j] == i + 'a') {
                        int left = helper(start, j, s, k);
                        int right = helper(j + 1, end, s, k);
                        return max(left, right);
                    }
                }
                
            }
        }
        return end - start;
    }
};