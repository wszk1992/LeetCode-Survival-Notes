/*
test case:
12563(no dups of the largest digit) --> 62513
12663(no leading largest digits) --> 62613 
612663(leading largest digits) --> 662613
0 --> 0

*/
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> count(10);
        int index = 1;
        int temp = num;
        while(temp) {
            count[temp % 10]++;
            temp /= 10;
            index *= 10;
        }
        index /= 10;
        int i = 9;
        while(index) {
            while(i >= 0 && count[i] == 0) {
                i--;
            }
            if(i < 0) return num;
            int curDigit = (num / index) % 10;
            if(curDigit == i) {
                count[i]--;
            } else {
                //find the last position of max digit
                int temp = num;
                int maxIndex = 1;
                while(temp) {
                    if(temp % 10 == i) {
                        break;
                    }
                    maxIndex *= 10;
                    temp /= 10;
                }
                return swapTwoDigits(num, index, maxIndex);
            }
            index /= 10;
        }
        return num;
        
    }
    
    int swapTwoDigits(int num, int i1, int i2) {
        //num   2    7   3    6
        //index 1000 100 10   1
        int d1 = (num / i1) % 10;
        int d2 = (num / i2) % 10;
        num -= d1 * i1 + d2 * i2;
        num += d1 * i2 + d2 * i1;
        return num;
    }
};