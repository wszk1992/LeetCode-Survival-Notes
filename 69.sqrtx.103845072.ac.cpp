class Solution {
public:
    int mySqrt(int x) {
        long left = 1;
        long right = x;
        long mid = (left + right) / 2;
        long target = x;
        while(!(mid * mid <= target && (mid+1) * (mid+1) > target)) {
            if((mid+1) * (mid+1) <= target) {
                left = mid + 1;
            } else if(mid * mid > target){
                right = mid;
            } else {
                break;
            }
            mid = (left + right) / 2;
        }
        return mid;
    }
};