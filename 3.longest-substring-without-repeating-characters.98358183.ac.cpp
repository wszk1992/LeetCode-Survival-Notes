class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<256> set;
        queue<char> q;
        int max_len = 0;
        for(int i = 0; i < s.length(); i++) {
            if(set[s[i]]) {
                while(q.front() != s[i]) {
                    set[q.front()] = 0;
                    q.pop();
                }
                q.pop();
            }
            q.push(s[i]);
            set[s[i]] = 1;
            max_len = q.size() > max_len ? q.size() : max_len;
        }
        return max_len;
    }
};