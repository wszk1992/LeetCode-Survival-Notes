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
    int closestValue(TreeNode* root, double target) {
        if(target < root->val) {
            if(root->left) {
                int left = closestValue(root->left, target);
                return root->val - target < abs(left - target) ? root->val : left;
            } else {
                return root->val;
            }
        } else if(target > root->val) {
            if(root->right) {
                int right = closestValue(root->right, target);
                return target - root->val < abs(right - target) ? root->val : right;
            } else {
                return root->val;
            }
        }
        return root->val;
    }
};