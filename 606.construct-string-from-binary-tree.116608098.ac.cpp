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
    string tree2str(TreeNode* t) {
        if(t == NULL) {
            return "";
        }
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        // left !empty right !empty --> (left)(right)
        // left empty right !empty --> ()(right)
        // left !empty right empty --> (left)
        // left empty right empty --> 
        return to_string(t->val) + (!left.empty() ? "(" + left + ")" : !right.empty() ? "()" : "") + (right.empty() ? "" : "(" + right + ")");
     }
};