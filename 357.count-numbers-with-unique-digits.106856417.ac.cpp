class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        for(int i = 1; i <= n && i < 10; i++) {
            int count = 9;
            int start = 9;
            for(int j = 1; j < i; j++) {
                count *= start--;
            }
            sum += count;
        }
        return sum;
    }
};