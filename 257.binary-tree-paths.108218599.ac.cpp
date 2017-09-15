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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(!root) {
            return paths;
        }
        string s = to_string(root->val);
        vector<string> leftPaths = binaryTreePaths(root->left);
        vector<string> rightPaths = binaryTreePaths(root->right);
        paths = leftPaths;
        paths.insert(paths.end(), rightPaths.begin(), rightPaths.end());
        if(paths.empty()) {
            return vector<string>(1, s);
        }
        for(int i = 0; i < paths.size(); i++) {
            paths[i] = s + "->" + paths[i];
        }
        return paths;
    }
};