class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        vector<string> p;
        string curPath;
        string res;
        for(char c : path) {
            if(c == '/') {
                if(!curPath.empty()) {
                    if(curPath == "..") {
                        //corner case: /../
                        if(!p.empty()) {
                            p.pop_back();
                        }
                    } else if(curPath != ".") {
                        p.push_back(curPath);
                    }
                    curPath.clear();
                }
            } else {
                curPath += c;
            }
        }
        if(p.empty()) {
            return "/";
        }
        for(string s : p) {
            res += "/" + s;
        }
        return res;
    }
};