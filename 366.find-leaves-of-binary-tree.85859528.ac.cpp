/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root);
        return res;
    }
    
    int dfs(vector<vector<int>>& res, TreeNode* root) {
        if(!root) {
            return -1;
        }
        int leftHeight = dfs(res, root->left);
        int rightHeight = dfs(res, root->right);
        int height = max(leftHeight, rightHeight) + 1;
        if(height >= res.size()) {
            res.push_back(vector<int>(1, root->val));
        } else {
            res[height].push_back(root->val);
        }
        return height;
    }
};