class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty()) {
            return 0;
        }
        //binary search
        int m = image.size(), n = image[0].size();
        int top = x, bot = x, left = y, right = y;
        //find top border;
        int t = 0, b = x;
        while(t < b) {
            int mid = (t + b) / 2;
            if(hasBlackInRow(image, mid)) {
                b = mid;
            } else {
                t = mid + 1;
            }
        }
        top = t;
        //find bottom border
        t = x + 1, b = m;
        while(t < b) {
            int mid = (t + b) / 2;
            if(hasBlackInRow(image, mid)) {
                t = mid + 1;
            } else {
                b = mid;
            }
        }
        bot = b;
        //find left border
        int l = 0, r = y;
        while(l < r) {
            int mid = (l + r) / 2;
            if(hasBlackInCol(image, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        left = l;
        //find right border
        l = y + 1, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(hasBlackInCol(image, mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        right = r;
        return (right - left) * (bot - top);
    }
    
    bool hasBlackInCol(vector<vector<char>>& image, int col) {
        for(int i = 0; i < image.size(); i++) {
            if(image[i][col] == '1') {
                return true;
            }
        }
        return false;
    }
    
    bool hasBlackInRow(vector<vector<char>>& image, int row) {
        for(int j = 0; j < image[0].size(); j++) {
            if(image[row][j] == '1') {
                return true;
            }
        }
        return false;
    }
};