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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            if(s.top() != NULL) {
                res.push_back(s.top()->val);
                s.push(s.top()->left);
            }else {
                s.pop();
                if(s.empty()) {
                    break;
                }
                TreeNode* node = s.top();
                s.pop();
                s.push(node->right);
            }
        }
        return res;
    }
};