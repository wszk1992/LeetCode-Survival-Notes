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
    int findBottomLeftValue(TreeNode* root) {
        //dfs
        int left;
        int maxLevel = -1;
        int level = 0;
        dfs(root, left, maxLevel, level);
        return left;
    }
    
    void dfs(TreeNode* root, int& left, int& maxLevel, int& level) {
        if(level > maxLevel) {
            maxLevel = level;
            left = root->val;
        }
        if(root->left) {
            dfs(root->left, left, maxLevel, ++level);
            level--;
        }
        if(root->right) {
            dfs(root->right, left, maxLevel, ++level);
            level--;
        }
    }
};