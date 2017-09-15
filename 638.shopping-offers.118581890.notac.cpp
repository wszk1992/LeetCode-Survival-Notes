class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<int, int> mem;
        int n = needs.size();
        vector<int> needList = needs;
        mem[0] = 0;
        return minPrice(needList, mem, price, special);
    }
    
    int minPrice(vector<int>& needList, unordered_map<int, int>& mem, vector<int>& price, vector<vector<int>>& special) {
        int key = 0;
        for(int i = 0; i < needList.size(); i++) {
            key = key * 7 + needList[i];
        }
        if(mem.count(key)) {
            return mem[key];
        }
        
        
        int minCost = INT_MAX;
        
        for(auto sp : special) {
            bool canUse = true;
            for(int i = 0; i < sp.size()-1; i++) {
                needList[i] -= sp[i];
                if(needList[i] < 0) {
                    canUse = false;
                }
            }
            if(canUse) {
                minCost = min(minCost, minPrice(needList, mem, price, special) + sp.back());
            }
            for(int i = 0; i < sp.size()-1; i++) {
                needList[i] += sp[i];
            }
        }
        for(int i = 0; i < price.size(); i++) {
            if(needList[i] - 1 >= 0) {
                needList[i]--;
                minCost = min(minCost, minPrice(needList, mem, price, special) + price[i]);
                needList[i]++;
            }
        }
        
        return mem[key] = minCost;
    }
};