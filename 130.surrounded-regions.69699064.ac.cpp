class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) {
            return;
        }
        int row = board.size();
        int col = board[0].size();
        int i, j;
        for(j = 0; j < col; j++) {
            if(board[0][j] == 'O') {
                board[0][j] = '.';
                bfs(board, 0, j);
            }
            if(board[row - 1][j] == 'O') {
                board[row - 1][j] = '.';
                bfs(board, row - 1, j);
            }
        }
        for(i = 1; i < row - 1; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = '.';
                bfs(board, i, 0);
            }
            if(board[i][col - 1] == 'O') {
                board[i][col - 1] = '.';
                bfs(board, i, col - 1);
            }
        }
        
        for(i = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                board[i][j] = board[i][j] == '.' ? 'O' : 'X';
            }
        }
    }
    
    void bfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> q;
        q.push(pair<int, int>(i, j));
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            if(r > 0 && board[r - 1][c] == 'O') {
                board[r - 1][c] = '.';
                q.push(pair<int, int>(r - 1, c));
            }
            if(r < board.size() - 1 && board[r + 1][c] == 'O') {
                board[r + 1][c] = '.';
                q.push(pair<int, int>(r + 1, c));
            }
            if(c > 0 && board[r][c - 1] == 'O') {
                board[r][c - 1] = '.';
                q.push(pair<int, int>(r, c - 1));
            }
            if(c < board[0].size() - 1 && board[r][c + 1] == 'O') {
                board[r][c + 1] = '.';
                q.push(pair<int, int>(r, c + 1));
            }
            q.pop();
        }
    }

};