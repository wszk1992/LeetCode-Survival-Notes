class NumArray {
private:
    struct SegNode {
        int sum;
        int start;
        int end;
        SegNode* left;
        SegNode* right;
        SegNode(int _start, int _end, int _sum = 0) : start(_start), end(_end), sum(_sum), left(NULL), right(NULL) {}
    };
    vector<int> nums;
    SegNode* root;
public:
    NumArray(vector<int> nums) {
        root = buildSegmentTree(nums, 0, nums.size());
        this->nums = nums;
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        getNewSum(root, i, diff);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int start = i, end = j + 1;
        return getSumRange(root, start, end);
    }
    
    SegNode* buildSegmentTree(vector<int>& nums, int i, int j) {
        if(i == j) return NULL;
        if(i + 1 == j) return new SegNode(i, j, nums[i]);
        SegNode* root = new SegNode(i, j);
        int mid = (i + j) / 2;
        root->left = buildSegmentTree(nums, i, mid);
        root->right = buildSegmentTree(nums, mid, j);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    int getSumRange(SegNode* root, int& i, int& j) {
        if(i >= root->end || j <= root->start) {
            // cout << "no intersection" << endl;
            return 0;
        } else if(i <= root->start && j >= root->end) {
            // cout << "[  [ ]  ]" << endl;
            //          i  s e  j
            return root->sum;
        } else {
            // cout << "add together" << endl;
            return getSumRange(root->left, i, j) + getSumRange(root->right, i, j);
        }
    }
    
    void getNewSum(SegNode* root, int& i, int& val) {
        if(root->start + 1 == root->end) {
            root->sum += val;
            return;
        }
        int mid = (root->start + root->end) / 2;
        if(i < mid)  getNewSum(root->left, i, val);
        else getNewSum(root->right, i, val);
        root->sum += val;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */