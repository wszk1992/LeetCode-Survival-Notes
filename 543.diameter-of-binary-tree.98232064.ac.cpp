/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct nodeInfo {
    int diameter;
    int height;
    nodeInfo() : diameter(0), height(-1) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        nodeInfo res = dbtHelper(root);
        return res.diameter;
        return 1;
    }
    
    nodeInfo dbtHelper(TreeNode* root) {
        nodeInfo res;
        if(root == NULL) {
            return res;
        }
        nodeInfo left = dbtHelper(root->left);
        nodeInfo right = dbtHelper(root->right);
        res.diameter = max(max(left.diameter, right.diameter), left.height + right.height + 2);
        res.height = max(left.height, right.height) + 1;
        //cout << res.diameter << "," << res.height << endl;
        return res;
    }
};