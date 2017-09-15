class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) {
            return "";
        }
        if(s.length() == 1) {
            return s == t ? s : "";
        }
        vector<int> dict(256, 0);
        int num = 0;
        for(char c : t) {
            dict[c]++;
            num++;
        }
        vector<int> count(256, 0);
        int numOfChar = 0;
        int left = 0;
        int right = -1;
        int minWindow = INT_MAX;
        int minLeft = 0;
        int minRight = 0;
        while(right < (int)s.length() - 1 || numOfChar == num) {
            if(numOfChar < num) {
                //right expend
                right++;
                if(dict[s[right]]) {
                    count[s[right]]++;
                    if(count[s[right]] <= dict[s[right]]) {
                        numOfChar++;
                    }
                }
            } else {
                //left shrink
                if(dict[s[left]]) {
                    count[s[left]]--;
                    if(count[s[left]] < dict[s[left]]) {
                        numOfChar--;
                    }
                }
                left++;
            }
            
            if(numOfChar == num) {
                if(right - left + 1 < minWindow) {
                    minLeft = left;
                    minRight = right;
                    minWindow = right - left + 1;
                }
            }
            
            
        }
        return minWindow == INT_MAX ? "" : s.substr(minLeft, minRight - minLeft + 1);
    }
};

