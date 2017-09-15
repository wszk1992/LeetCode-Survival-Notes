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
    vector<int> largestValues(TreeNode* root) {
        vector<int> values;
        if(!root) {
            return values;
        }
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()) {
            int size = level.size();
            int maxValue = INT_MIN;
            while(size--) {
                TreeNode* cur = level.front();
                level.pop();
                maxValue = max(maxValue, cur->val);
                if(cur->left) {
                    level.push(cur->left);
                }
                if(cur->right) {
                    level.push(cur->right);
                }
            }
            values.push_back(maxValue);
        }
        return values;
    }
};