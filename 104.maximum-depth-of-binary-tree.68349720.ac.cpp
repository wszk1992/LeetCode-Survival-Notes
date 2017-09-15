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
//bfs
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            depth++;
            for(int i = 0, n = q.size(); i < n; i++) {
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return depth;
    }
};