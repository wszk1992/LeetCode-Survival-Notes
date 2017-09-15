class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) {
            return;
        }
        int m = rooms.size(), n = rooms[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0) {
                    bfs(rooms, i, j);
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>& rooms, int i, int j) {
        int m = rooms.size(), n = rooms[0].size();
        int dis = 0;
        queue<pair<int, int>> awaitRooms;
        awaitRooms.push(make_pair(i, j));
        while(!awaitRooms.empty()) {
            int size = awaitRooms.size();
            while(size--) {
                pair<int, int> room = awaitRooms.front();
                rooms[room.first][room.second] = dis;
                for(int y = 0; y < 2; y++) {
                    for(int x = 0; x < 2; x++) {
                        int row = y == 0 ? room.first : room.first + x * 2 - 1;
                        int col = y == 0 ? room.second + x * 2 - 1 : room.second;
                        if(row >= 0 && row < m && col >= 0 && col < n && rooms[row][col] > dis + 1) {
                            awaitRooms.push(make_pair(row, col));
                        }
                    }
                }
                awaitRooms.pop();
            }
            dis++;
        }
    }
};