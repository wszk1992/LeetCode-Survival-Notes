class Solution {
public:
    int findNthDigit(int n) {
        int i = 1;
        while(n > 9 * power(10, i - 1) * i) {
            n -= 9 * power(10, i - 1) * i;
            i++;
        }
        int start = power(10, i - 1);
        int num = (n - 1) / i + start;
        for(int k = 0; k < i - 1 - (n - 1) % i; k++) {
            num /= 10;
        }
        return num % 10;
    }
    
    long power(int base, int p) {
        long res = 1;
        while(p--) {
            res *= base;
        }
        return res;
    }
}; 