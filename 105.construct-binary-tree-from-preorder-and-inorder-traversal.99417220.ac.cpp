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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* buildHelper(vector<int>& preorder, int pBegin, int pEnd, vector<int>& inorder, int iBegin, int iEnd) {
        if(pBegin == pEnd || iBegin == iEnd) {
            return NULL;
        }
        int val = preorder[pBegin];
        TreeNode *root = new TreeNode(val);
        int index = findIndex(inorder, val);
        root->left = buildHelper(preorder, pBegin+1, pBegin+1+index-iBegin, inorder, iBegin, index);
        root->right = buildHelper(preorder, pBegin+1+index-iBegin, pEnd, inorder, index+1, iEnd);
        return root;
    }
    
    int findIndex(vector<int>& vec, int element) {
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == element) {
                return i;
            }
        }
        return -1;
    }
};