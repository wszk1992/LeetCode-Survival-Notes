class TicTacToe {
public:
    vector<vector<int>> rowNum, colNum;
    //@rowNum[0] = number of player 1's marks in each row
    //@rowNum[1] = number of player 2's marks in each row
    //@colNum[0] = number of player 1's marks in each column
    //@colNum[1] = number of player 2's marks in each column
    vector<pair<int, int>> diag;
    //@diag[0] = number of player 1's marks in two diagonal
    //@diag[1] = number of player 2's marks in two diagonal
    int n;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        rowNum = colNum = vector<vector<int>>(2, vector<int>(n, 0));
        diag = vector<pair<int, int>>(2, pair<int, int>(0, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        rowNum[player - 1][row]++;
        colNum[player - 1][col]++;
        if(col == row) {
            diag[player - 1].first++;
        }
        if(col + row == n - 1) {
            diag[player - 1].second++;
        }
        if(rowNum[player - 1][row] == n || colNum[player - 1][col] == n || diag[player - 1].first == n || diag[player - 1].second == n) {
            return player;
        } else {
            return 0;
        }
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */