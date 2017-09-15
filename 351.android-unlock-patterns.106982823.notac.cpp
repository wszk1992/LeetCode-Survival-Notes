class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> arrived(9, 0);
        int corner = 0, side = 0, center = 0;
        dfs(arrived, 0, m, n, 1, corner);
        dfs(arrived, 1, m, n, 1, side);
        dfs(arrived, 4, m, n, 1, center);
        return 4 * corner + 4 * side + center;
    }
    
    void dfs(vector<bool>& arrived, int pos, int& m, int& n, int step, int& count) {
        arrived[pos] = 1;
        if(step > n) {
            arrived[pos] = 0;
            return;
        }
        if(step >= m) {
            count++;
        }
        vector<int> next = nextPos(arrived, pos);
        for(int i = 0; i < next.size(); i++) {
            dfs(arrived, next[i], m, n, step + 1, count);
        }
        arrived[pos] = 0;
    }
    
    vector<int> nextPos(vector<bool>& arrived, int pos) {
        vector<int> next;
        if(isSide(pos)) {
            //pos is on the side
            for(int i = 0; i < 9; i++) {
                if(i == 4) {
                    if(!arrived[i]) {
                        next.push_back(i);
                    } else if(!arrived[8 - pos]) {
                        next.push_back(8 - pos);
                    }
                } else if(!arrived[i] && i != 8 - pos) {
                    next.push_back(i);
                }
            }
        } else if(pos == 4) {
            //pos is on the center
            for(int i = 0; i < 9; i++) {
                if(!arrived[i]) {
                    next.push_back(i);
                }
            }
        } else {
            //pos is on the corner
            for(int i = 0; i < 9; i++) {
                if(isCorner(i)) {
                    continue;
                }
                if(abs(i - pos) == 1 || abs(i - pos) == 3 || i == 4) {
                    if(!arrived[i]) {
                        next.push_back(i);
                    } else if(!arrived[2 * i - pos]){
                        next.push_back(2 * i - pos);
                    }
                } else if(!arrived[i]){
                    next.push_back(i);
                }
            }
        }
        return next;
    }
    
    vector<int> getSides() {
        return {1,3,5,7};
    }
    vector<int> getCorners() {
        return {0,2,6,8};
    }
    
    bool isSide(int pos) {
        vector<int> sides = getSides();
        for(int s : sides) {
            if(pos == s) {
                return true;
            }
        }
        return false;
    }
    
    bool isCorner(int pos) {
        return !isSide(pos) && pos != 4;
    }
};