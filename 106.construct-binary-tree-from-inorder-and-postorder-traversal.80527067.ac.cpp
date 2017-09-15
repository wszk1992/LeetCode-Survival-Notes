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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> getIndex;
        for(int i = 0; i < inorder.size(); i++) {
            getIndex[inorder[i]] = i;
        }
        return helper(getIndex, inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode* helper(unordered_map<int, int>& getIndex, vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend) {
        if(instart == inend) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postend - 1]);
        int i = getIndex[postorder[postend - 1]];
        root->left = helper(getIndex, inorder, instart, i, postorder, poststart, poststart + i - instart);
        root->right = helper(getIndex, inorder, i + 1, inend, postorder, poststart + i - instart, postend - 1);
        return root;
    }
};