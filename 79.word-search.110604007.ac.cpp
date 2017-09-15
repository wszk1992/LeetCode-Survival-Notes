class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) {
            return false;
        }
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> arrived(m, vector<bool>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(dfs(board, arrived, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& arrived, string& word, int i, int j, int k) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || arrived[i][j] || board[i][j] != word[k]) {
            return false;
        }
        if(k == word.size() - 1) {
            return true;
        }
        arrived[i][j] = true;
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        for(auto dir : dirs) {
            if(dfs(board, arrived, word, i + dir[0], j + dir[1], k + 1)) {
                return true;
            }
        }
        arrived[i][j] = false;
        return false;
    }
};