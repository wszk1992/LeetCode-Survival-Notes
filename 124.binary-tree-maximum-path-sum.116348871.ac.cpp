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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathFromRoot(root, maxSum);
        return maxSum;
    }
    
    int maxPathFromRoot(TreeNode* root, int& maxSum) {
        if(root == NULL) {
            return 0;
        }
        int left = maxPathFromRoot(root->left, maxSum);
        int right = maxPathFromRoot(root->right, maxSum);
        maxSum = max(maxSum, (left > 0 ? left : 0) + root->val + (right > 0 ? right : 0));
        return max(max(left, right) + root->val, root->val);
    }
};