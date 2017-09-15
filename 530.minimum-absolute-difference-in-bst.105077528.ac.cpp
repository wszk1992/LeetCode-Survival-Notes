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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        getMinAndMax(root, minDiff);
        return minDiff;
    }
    
    //@return pair(min, max);
    pair<int, int> getMinAndMax(TreeNode* root, int& minDiff) {
        if(!root) {
            return pair<int, int>(0, 0);
        }
        pair<int, int> left = getMinAndMax(root->left, minDiff);
        pair<int, int> right = getMinAndMax(root->right, minDiff);
        int leftMinDiff = root->left ? root->val - left.second : INT_MAX;
        int rightMinDiff = root->right ? right.first - root->val  : INT_MAX;
        minDiff = min(minDiff, min(leftMinDiff, rightMinDiff));
        return make_pair(root->left ? left.first : root->val, root->right ? right.second : root->val);
    }
};