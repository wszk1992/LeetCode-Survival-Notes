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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            if(s.top() != NULL) {
                s.push(s.top()->left);
            }else {
                s.pop();
                if(s.empty()) {
                    break;
                }
                TreeNode* node = s.top();
                s.pop();
                res.push_back(node->val);
                s.push(node->right);
            }
        }
        return res;
    }
};