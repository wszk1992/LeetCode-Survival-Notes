class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k = 3;
        int m1 = 0, m2 = 0;
        for(int num : nums) {
            m2 ^= m1 & num;
            m1 ^= num;
            int mask = ~(m1 & m2);
            m1 &= mask;
            m2 &= mask;
        }
        return m1;
    }
};