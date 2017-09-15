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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty()) {
            vector<int> level;
            int num1 = s1.size();
            while(num1--) {
                TreeNode* curNode = s1.top();
                if(curNode->left) {
                    s2.push(curNode->left);
                }
                if(curNode->right) {
                    s2.push(curNode->right);
                }
                level.push_back(curNode->val);
                s1.pop();
            }
            res.push_back(level);
            level.clear();
            int num2 = s2.size();
            while(num2--) {
                TreeNode* curNode = s2.top();
                if(curNode->right) {
                    s1.push(curNode->right);
                }
                if(curNode->left) {
                    s1.push(curNode->left);
                }
                level.push_back(curNode->val);
                s2.pop();
            }
            if(!level.empty()) {
                res.push_back(level);
            }
        }
        return res;
    }
};