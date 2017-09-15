class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorOfTwo = 0;
        for(int num : nums) {
            xorOfTwo ^= num;
        }
        int i = 0;
        while(i < 32 && !(xorOfTwo & 1 << i)) {
            i++;
        }
        int num1 = 0, num2 = 0;
        for(int num : nums) {
            if(num & 1 << i) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        vector<int> res;
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
};