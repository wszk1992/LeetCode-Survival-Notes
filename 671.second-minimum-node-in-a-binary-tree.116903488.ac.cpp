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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        int minVal = root->val;
        int secMinVal = INT_MAX;
        dfs(root, minVal, secMinVal);
        return secMinVal == INT_MAX ? -1 : secMinVal;
    }
    
    void dfs(TreeNode* root, int& minVal, int& secMinVal) {
        if(!root) {
            return;
        }
        if(root->val == minVal) {
            dfs(root->left, minVal, secMinVal);
            dfs(root->right, minVal, secMinVal);
        } else {
            secMinVal = min(secMinVal, root->val);
        }
    }
};