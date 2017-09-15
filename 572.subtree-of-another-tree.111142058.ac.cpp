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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL) {
            return t == NULL;
        }
        return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSame(TreeNode* s, TreeNode* t) {
        if(s == NULL || t == NULL) {
            return s == t;
        }
        return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};