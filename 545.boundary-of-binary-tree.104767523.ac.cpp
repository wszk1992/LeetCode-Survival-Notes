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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) {
            return vector<int>();
        }
        vector<int> boundary(1, root->val);
        vector<int> rightboundary;
        
        //left boundary
        TreeNode* p = root;
        if(p->left) {
            p = p->left;
            while(p->left || p->right) {
                boundary.push_back(p->val);
                if(p->left) {
                    p = p->left;
                } else {
                    p = p->right;
                }
            }
        }
        
        //leaves
        if(root->left || root->right) {
            inorderTraversal(root, boundary);
        }
        
        //right boundary
        p = root;
        if(p->right) {
            p = p->right;
            while(p->left || p->right) {
                rightboundary.push_back(p->val);
                if(p->right) {
                    p = p->right;
                } else {
                    p = p->left;
                }
            }
            reverse(rightboundary.begin(), rightboundary.end());
            boundary.insert(boundary.end(), rightboundary.begin(), rightboundary.end());
        }
        
        return boundary;
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& boundary) {
        if(!root->left && !root->right) {
            boundary.push_back(root->val);
            return;
        }
        if(root->left) {
            inorderTraversal(root->left, boundary);
        }
        if(root->right) {
            inorderTraversal(root->right, boundary);
        }
    }
};