class Solution {
public:
    int nextGreaterElement(int n) {
        long target = n;
        vector<int> cache;
        while(target) {
            int cur = target % 10;
            target /= 10;
            if(!cache.empty() && cur < cache.back()) {
                //find smallest element in cache larger than cur
                for(int i = 0; i < cache.size(); i++) {
                    if(cache[i] > cur) {
                        //switch cur with cache[i]
                        target = 10 * target + cache[i];
                        cache[i] = cur;
                        break;
                    }
                }
                for(int i = 0; i < cache.size(); i++) {
                    target = 10 * target + cache[i];
                }
                return target <= INT_MAX ? target : -1;
            } else {
                cache.push_back(cur);
            }
        }
        return -1;
    }

};