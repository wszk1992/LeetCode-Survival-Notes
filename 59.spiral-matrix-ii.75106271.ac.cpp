class Solution {
public:
    enum Dir {right, down, left, up};
    
    void go(Dir d, pair<int, int>& pos) {
        switch(d) {
            case right: pos = pair<int, int>(pos.first, pos.second + 1); break;
            case down: pos = pair<int, int>(pos.first + 1, pos.second); break;
            case left: pos = pair<int, int>(pos.first, pos.second - 1); break;
            case up: pos = pair<int, int>(pos.first - 1, pos.second); break;
            default: break;
        }
    }
    
    void turn(Dir& d) {
        switch(d) {
            case right: d = down; break;
            case down: d = left; break;
            case left: d = up; break;
            case up: d = right; break;
            default: break; 
        }
    }
    
    bool shouldTurn(Dir& d, pair<int, int>& pos, int& m, int& n, vector<vector<int>>& trace) {
        switch(d) {
            case right: return pos.second + 1 == n || trace[pos.first][pos.second + 1] != 0; break;
            case down: return pos.first + 1 == m || trace[pos.first + 1][pos.second] != 0; break;
            case left: return pos.second == 0 || trace[pos.first][pos.second - 1] != 0; break;
            case up: return pos.first == 0 || trace[pos.first - 1][pos.second] != 0; break;
            default: return false; break;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        Dir d;
        pair<int, int> pos(0, -1);
        int i = 0;
        int num = n * n;
        while(i < num) {
            if(shouldTurn(d, pos, n, n, res)) {
                turn(d);
                go(d, pos);
            }else {
                go(d, pos);
            }
            res[pos.first][pos.second] = ++i;
        }
        return res;
    }
};