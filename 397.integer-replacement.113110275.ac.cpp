class Solution {
public:
    int integerReplacement(int n) {
        //2->1  3->2 4->2
        if(n <= 3) return n - 1;
        //4n 4n+1 4n+2 4n+3
        int remaining = n % 4;
        switch(remaining) {
            case 0: return 2 + integerReplacement(n / 4);
            case 1: return 1 + integerReplacement(n - 1);
            case 2: return 1 + integerReplacement(n / 2);
            case 3: return 3 + integerReplacement((n-3)/4+1);
        }
    }
};