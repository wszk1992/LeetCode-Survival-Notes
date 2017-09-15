class Solution {
public:
    int totalNQueens(int n) {
        vector<int> flag(5 * n - 2, 1);
    	int res = 0;
        totalNQueens(flag, 0, n, res);
    	return res;
    }
    void totalNQueens(std::vector<int> &flag, int row, int &n, int &res) {
        if (row == n) {
            ++res;
	    return;
        }
        for (int col = 0; col != n; ++col)
            if (flag[col] && flag[col + row + n] && flag[col - row + 4 * n - 2]) {
                flag[col] = flag[col + row + n] = flag[col - row + 4 * n - 2] = 0;
                totalNQueens(flag, row + 1, n, res);
                flag[col] = flag[col + row + n] = flag[col - row + 4 * n - 2] = 1;
            }
    }
    
};