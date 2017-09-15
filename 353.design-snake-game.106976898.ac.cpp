class SnakeGame {
public:
    /*
        @param board - screen
        @param snake - list of snake's body, front -> tail, back -> head
    */
    vector<vector<bool>> board;
    queue<pair<int, int>> snake;
    vector<pair<int, int>> food;
    int score;
    int width, height;
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        board = vector<vector<bool>>(height, vector<bool>(width, 0));
        board[0][0] = 1;
        snake.push(make_pair(0, 0));
        score = 0;
        this->food = food;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        int i = direction == "U" ? 0 : direction == "L" ? 1 : direction == "R" ? 2 : 3;
        int row = snake.back().first + dir[i][0], col = snake.back().second + dir[i][1];
        if(row < 0 || row >= height || col < 0 || col >= width) {
            return -1;
        } else if(score < food.size() && row == food[score].first && col == food[score].second) {
            board[row][col] = 1;
            snake.push(make_pair(row, col));
            score++;
        } else {
            board[snake.front().first][snake.front().second] = 0;
            if(board[row][col]) {
                return -1;
            }
            board[row][col] = 1;
            snake.pop();
            snake.push(make_pair(row, col));
        }
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */