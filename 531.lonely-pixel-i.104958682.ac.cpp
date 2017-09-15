class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.empty() || picture[0].empty()) {
            return 0;
        }
        int num = 0;
        int m = picture.size(), n = picture[0].size();
        vector<int> rowB(m, 0);
        vector<int> rowBPos(m, 0);
        vector<int> colB(n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(picture[i][j] == 'B') {
                    rowB[i]++;
                    rowBPos[i] = j;
                    colB[j]++;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            if(rowB[i] == 1 && colB[rowBPos[i]] == 1) {
                num++;
            }
        }
        return num;
    }
};