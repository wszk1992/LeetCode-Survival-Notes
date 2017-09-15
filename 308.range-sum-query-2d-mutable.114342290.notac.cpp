class NumMatrix {
private:
    struct SegNode {
        int sum;
        int row1, col1, row2, col2;
        //lt, rt, lb, tb
        vector<SegNode*> seg;
        SegNode(int _row1, int _col1, int _row2, int _col2, int _sum = 0) :
            sum(_sum), 
            row1(_row1),
            col1(_col1),
            row2(_row2),
            col2(_col2),
            seg(vector<SegNode*>(4, NULL)) {}
    };
    SegNode* root;
public:
    NumMatrix(vector<vector<int>> matrix) {
        root = matrix.empty() ? NULL : buildSegmentTree(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1);
    }
    
    void update(int row, int col, int val) {
        getUpdate(row, col, val, root);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSumRegin(row1, col1, row2, col2, root);
    }
    
    SegNode* buildSegmentTree(vector<vector<int>>& matrix, int row1, int col1, int row2, int col2) {
        if(row1 > row2 || col1 > col2) {
            return NULL;
        }
        if(row1 == row2 && col1 == col2) {
            return new SegNode(row1, col1, row2, col2, matrix[row1][col1]);
        }
        int rowC = (row1 + row2) / 2;
        int colC = (col1 + col2) / 2;
        SegNode* root = new SegNode(row1, col1, row2, col2);
        root->seg[0] = buildSegmentTree(matrix, row1, col1, rowC, colC);
        root->seg[1] = buildSegmentTree(matrix, row1, colC+1, rowC, col2);
        root->seg[2] = buildSegmentTree(matrix, rowC+1, col1, row2, colC);
        root->seg[3] = buildSegmentTree(matrix, rowC+1, colC+1, row2, col2);
        for(int i = 0; i < 4; i++) {
            if(root->seg[i]) {
                root->sum += root->seg[i]->sum;
            }
        }
        return root;
    }
    
    int getSumRegin(int& row1, int& col1, int& row2, int& col2, SegNode* root) {
        if(root == NULL || root->row2 < row1 || root->col2 < col1 || root->row1 > row2 || root->col1 > col2) {
            //no intersection
            return 0;
        } else if(root->row1 >= row1 && root->col1 >= col1 && root->row2 <= row2 && root->col2 <= col2) {
            //root is a subset of the sumRegin
            return root->sum;
        } else {
            int sum = 0;
            for(int i = 0; i < 4; i++) {
                sum += getSumRegin(row1, col1, row2, col2, root->seg[i]);
            }
            return sum;
        }
    }
    
    void getUpdate(int& row, int& col, int& val, SegNode* root) {
        if(root->row1 == root->row2 && root->row1 == row && root->col1 == root->col2 && root->col1 == col) {
            //find the position
            int diff = val - root->sum;
            root->sum = val;
            val = diff;
            return;
        }
        int rowC = (root->row1 + root->row2) / 2;
        int colC = (root->col1 + root->col2) / 2;
        if(row <= rowC) {
            if(col <= colC) {
                //leftTop
                getUpdate(row, col ,val, root->seg[0]);
            } else {
                //rightTop
                getUpdate(row, col, val, root->seg[1]);
            }
        } else {
            if(col <= colC) {
                //leftBot
                getUpdate(row, col, val, root->seg[2]);
            } else {
                //rightBot
                getUpdate(row, col, val, root->seg[3]);
            }
        }
        root->sum += val;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */