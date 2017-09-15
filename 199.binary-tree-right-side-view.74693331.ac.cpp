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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return vector<int>();
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            res.push_back(q.back()->val);
            int n = q.size();
            while(n--) {
                TreeNode* node = q.front();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                q.pop();
            }
        }
        
        return res;
    }
};