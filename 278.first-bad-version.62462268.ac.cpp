// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 0) {
            return -1;
        }
        int first = 1;
        int end = n;
        while(first + 1 < end) {
            int mid = first + (end - first) / 2;
            if(isBadVersion(mid)) {
                end = mid;
            }
            else {
                first = mid;
            }
        }
        
        if(isBadVersion(first)) {
            return first;
        }
        else if(isBadVersion(end)) {
            return end;
        }
        else {
            return -1;
        }
    }
};