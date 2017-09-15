// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if(res == -1) {
                right = mid;
            } else if(res == 1) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};