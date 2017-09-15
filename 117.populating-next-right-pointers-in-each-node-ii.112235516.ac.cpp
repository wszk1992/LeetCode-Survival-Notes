/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) {
            return;
        }
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeLinkNode* cur = q.front();
                q.pop();
                cur->next = n == 0 ? NULL : q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
    }
};