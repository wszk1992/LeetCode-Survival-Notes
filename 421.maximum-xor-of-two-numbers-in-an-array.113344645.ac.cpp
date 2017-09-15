class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 1 << 31;
        int maxXor = 0;
        for(int i = 31; i >= 0; i--) {
            unordered_set<int> dict;
            for(int num : nums) {
                dict.insert(num & mask);
            }
            int nextMaxXor = maxXor | 1 << i;
            for(int num : nums) {
                if(dict.count((num ^ nextMaxXor) & mask)) {
                    maxXor = nextMaxXor;
                    break;
                }
            }
            mask |= mask >> 1;
            // cout << bitset<32>(maxXor) << endl;
        }
        return maxXor;
    }
};