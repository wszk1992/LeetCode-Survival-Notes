class Solution {
private:
    struct BSTNode {
        int val;
        int leftCount;
        BSTNode* left;
        BSTNode* right;
        BSTNode(int v) : val(v), leftCount(0), left(NULL), right(NULL) {}
    };
public:    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n);
        if(n <= 1) {
            return count;
        }
        BSTNode* root = new BSTNode(nums[n-1]);
        for(int i = n-2; i >= 0; i--) {
            int cnt = 0;
            BSTNode* p = root;
            while(p) {
                if(nums[i] <= p->val) {
                    p->leftCount++;
                    if(p->left) {
                        p = p->left;
                    } else {
                        p->left = new BSTNode(nums[i]);
                        break;
                    }
                } else {
                    cnt += p->leftCount + 1;
                    if(p->right) {
                        p = p->right;
                    } else {
                        p->right = new BSTNode(nums[i]);
                        break;
                    }
                }
            }
            count[i] = cnt;
        }
        return count;
    }
};