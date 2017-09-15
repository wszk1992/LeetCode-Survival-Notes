class Solution {
public:
    string intToRoman(int num) {
        string romanList = "IVXLCDM";
        string s;
        int i = 0;
        while(num) {
            int bit = num % 10;
            if(bit >= 1 && bit <= 3) {
                s.insert(0, bit, romanList[i]);
            }else if(bit == 4) {
                s.insert(0, 1, romanList[i + 1]);
                s.insert(0, 1, romanList[i]);
            }else if(bit >= 5 && bit <= 8) {
                s.insert(0, bit - 5, romanList[i]);
                s.insert(0, 1, romanList[i + 1]);
            }else if(bit == 9){
                s.insert(0, 1, romanList[i + 2]);
                s.insert(0, 1, romanList[i]);
            }
            i += 2;
            num /= 10;
        }
        return s;
    }
};