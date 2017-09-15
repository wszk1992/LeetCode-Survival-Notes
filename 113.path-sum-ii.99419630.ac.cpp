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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        if(!root->left && !root->right && root->val == sum) {
            res.push_back(vector<int>(1, root->val));
            return res;
        }
        vector<vector<int>> left = pathSum(root->left, sum - root->val);
        vector<vector<int>> right = pathSum(root->right, sum - root->val);
        //combine two vector
        left.insert(left.end(), right.begin(), right.end());
        //add current value into path
        for(int i = 0; i < left.size(); i++) {
            left[i].insert(left[i].begin(), root->val);
        }
        return left;
    }
};