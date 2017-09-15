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
    bool isValidBST(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> map;
        return validHelper(root, map);
    }
    
    bool validHelper(TreeNode* root, unordered_map<TreeNode*, pair<int, int>>& map) {
        if(root == NULL) {
            return true;
        }
        bool res = false;
        if((root->left == NULL || validHelper(root->left, map) && root->val > map[root->left].second) &&
            (root->right == NULL || validHelper(root->right, map) && root->val < map[root->right].first)) {
                res = true;
                map[root] = make_pair(root->left ? map[root->left].first : root->val, root->right ? map[root->right].second : root->val);
            }
        return res;
        
    }
};