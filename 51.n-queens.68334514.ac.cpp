class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> s(n, string(n, '.'));
        solveNQueensHelper(res, s, n, 0);
        return res;
    }
    
    void solveNQueensHelper(vector<vector<string>>& res, vector<string>& s, int& n, int row) {
        if(row == n) {
            res.push_back(s);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!availablePos(s, n, row, i)) {
                continue;
            }else {
                s[row][i] = 'Q';
                solveNQueensHelper(res, s, n, row + 1);
                s[row][i] = '.';
            }
        }
    }
    
    bool availablePos(vector<string>& s, int& n, int& row, int& col) {
        //45°
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(s[i][j] == 'Q') {
                return false;
            }
        }
        //90°
        for(int i = row; i >= 0; i--) {
            if(s[i][col] == 'Q') {
                return false;
            }
        }
        //135°
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(s[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
    
};