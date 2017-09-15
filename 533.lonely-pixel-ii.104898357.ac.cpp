class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if(picture.empty() || picture[0].empty()) {
            return 0;
        }
        int m = picture.size(), n = picture[0].size();
        int pixels = 0;
        //a row can be presented by 8 chars
        //key: 8 chars, value: numOfRows)
        unordered_map<string, int> map;
        unordered_map<int, string> rowToString;
        for(int i = 0; i < m; i++) {
            string s;
            char c = 0;
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(j % 8 == 0) {
                    c = 0;
                }
                c <<= 1;
                if(picture[i][j] == 'W') {
                    c += 0;
                } else {
                    c += 1;
                    count++;
                }
                if(j % 8 == 7) {
                    s += c;
                }
            }
            if(n % 8 != 0) {
                s += c;
            }
            if(count == N) {
                if(map.count(s)) {
                    map[s]++;
                } else {
                    map[s] = 1;
                }
                rowToString[i] = s;
            }
            
        }
        
        for(int j = 0; j < n; j++) {
            string target;
            int count = 0;
            for(int i = 0; i < m; i++) {
                if(picture[i][j] == 'B') {
                    count++;
                }
            }
            if(count == N) {
                int i;
                for(i = 0; i < m; i++) {
                    if(picture[i][j] == 'B') {
                        if(!rowToString.count(i)) {
                            break;
                        } else if (target.empty()){
                            target = rowToString[i];
                        } else if(target != rowToString[i]) {
                            break;
                        }
                    }
                }
                if(i == m) {
                    pixels += map[target];
                }
            }
            
        }
        
        return pixels;
        
    }
};