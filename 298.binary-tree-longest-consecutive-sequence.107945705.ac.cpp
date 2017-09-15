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
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        dfs(root, 0, 0, longest);
        return longest;
    }
    
    void dfs(TreeNode* root, int last, int len, int& longest) {
        if(!root) {
            return;
        }
        if(last + 1 == root->val) {
            len++;
        } else {
            len = 1;
        }
        longest = max(longest, len);
        dfs(root->left, root->val, len, longest);
        dfs(root->right, root->val, len, longest);
    }
};