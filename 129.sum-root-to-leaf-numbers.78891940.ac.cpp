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
    int sumNumbers(TreeNode* root){
        if(!root) {
            return 0;
        }
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }
    
    void dfs(TreeNode* node, int& sum, int val) {
        if(!node->left && !node->right) {
            sum += node->val + val * 10;
        }else {
            if(node->left) {
                dfs(node->left, sum, node->val + val * 10);
            }
            if(node->right) {
                dfs(node->right, sum, node->val + val * 10);
            }
        }
    }
};