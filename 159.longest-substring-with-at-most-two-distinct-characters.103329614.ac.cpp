class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        queue<char> cache;
        vector<int> index(256, -1);
        int len = 0;
        int maxLen = 0;
        for(int i = 0; i < s.length(); i++) {
            index[s[i]] = i;
            if(cache.size() == 0) {
                cache.push(s[i]);
                len++;
            } else if(cache.size() == 1) {
                if(s[i] != cache.front()) {
                    cache.push(s[i]);
                }
                len++;
            } else {
                if(s[i] != cache.front() && s[i] != cache.back()) {
                    len = i - index[cache.front()];
                } else {
                    len++;
                }
                if(s[i] != cache.back()) {
                    cache.pop();
                    cache.push(s[i]);
                }
                
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};