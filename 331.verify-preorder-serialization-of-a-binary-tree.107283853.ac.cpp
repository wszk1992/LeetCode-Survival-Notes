class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder.push_back(',');
        vector<string> cache;
        string curNode;
        for(int i = 0; i < preorder.size(); i++) {
            if(preorder[i] == ',') {
                cache.push_back(curNode);
                while(cache.size() >= 2 && cache.back() == "#" && cache[cache.size() - 2] == "#") {
                    for(int i = 0; i < 3; i++) {
                        if(cache.empty()) {
                            return false;
                        }
                        cache.pop_back();
                    }
                    cache.push_back("#");
                }
                curNode = "";
            } else {
                curNode += preorder[i];
            }
        }
        return cache.size() == 1 && cache[0] == "#";
    }
};