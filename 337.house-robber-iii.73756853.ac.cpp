class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> res = robHelper(root);
        return max(res.first, res.second);
    }
    
    pair<int, int> robHelper(TreeNode* root) {
        if(root == NULL) {
            return pair<int, int>(0, 0);
        }
        pair<int, int> res;
        pair<int, int> left = robHelper(root->left);
        pair<int, int> right = robHelper(root->right);
        res.first = root->val + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        return res;
    }
};