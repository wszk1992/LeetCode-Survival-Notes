class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) {
            return true;
        }
        int front = 1;
        int end = num / 2;
        while(front <= end) {
            long mid = (front + end) / 2;
            if(mid * mid > num) {
                end = mid - 1;
            }else if(mid * mid < num){
                front = mid + 1;
            }else {
                return true;
            }
            cout << front << ", " << end << endl;
        }
        return false;
    }
};