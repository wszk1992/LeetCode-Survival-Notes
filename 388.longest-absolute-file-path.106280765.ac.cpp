class Solution {
public:
    int lengthLongestPath(string input) {
        input += '\n';
        int len = 0;
        int maxLen = 0;
        int curLevel = 0;
        stack<string> dir;
        string curDir;
        for(int i = 0; i < input.size(); i++) {
            if(input[i] == '\n') {
                while(curLevel < dir.size()) {
                    len -= dir.top().length() + 1;
                    dir.pop();
                }
                if(isFile(curDir)) {
                    maxLen = max(maxLen, len + (int)curDir.length());
                } else {
                    dir.push(curDir);
                    len += curDir.length() + 1;
                }
                curLevel = 0;
                curDir = "";
            } else if(input[i] == '\t') {
                curLevel++;
            } else {
                curDir += input[i];
            }
        }
        return maxLen;
        
    }
    
    bool isFile(string s) {
        return s.find('.') != string::npos;
    }
};