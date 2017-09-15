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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int num = q.size();
            while(num--) {
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                level.push_back(q.front()->val);
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};