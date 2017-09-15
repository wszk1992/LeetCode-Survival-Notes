class Solution {
public:
    string toHex(int num) {
        string hex;
        for(int i = 0; i < 8 && num; i++) {
            // cout << bitset<32>(num) << endl;
            hex += (num & 15) < 10 ? (num & 15) + '0' : (num & 15) - 10 + 'a';
            num >>= 4;
        }
        reverse(hex.begin(), hex.end());
        return hex.empty() ? "0" : hex;
    }
};