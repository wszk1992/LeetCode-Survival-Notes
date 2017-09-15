class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) {
            return;
        }
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int neighbor = neighborLives(board, i, j);
                if((board[i][j] && (neighbor == 2 || neighbor == 3)) || (!board[i][j] && neighbor == 3)) {
                    board[i][j] += 2;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
    int neighborLives(vector<vector<int>>& board, int row, int col) {
        int count = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) continue;
                int posI = row + i;
                int posJ = col + j;
                if(posI < board.size() && posI >= 0 && posJ < board[0].size() && posJ >= 0 && board[posI][posJ] & 1) {
                    count++;
                }
            }
        }
        return count;
    }
};