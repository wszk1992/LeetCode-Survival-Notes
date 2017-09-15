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
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        pair<int, int> p = dfs(root, longest);
        return longest;
    }
    
    pair<int, int> dfs(TreeNode* root, int& longest) {
        if(!root) {
            return make_pair(0, 0);
        }
        pair<int, int> left = dfs(root->left, longest);
        pair<int, int> right = dfs(root->right, longest);
        int increase = 1, decrease = 1;
        if(root->left) {
            if(root->val - 1 == root->left->val) {
                increase += left.first;
            } else if(root->val + 1 == root->left->val) {
                decrease += left.second;
            }
        }
        if(root->right) {
            if(root->val - 1 == root->right->val) {
                increase = max(increase, right.first + 1);
            } else if(root->val + 1 == root->right->val) {
                decrease = max(decrease, right.second + 1);
            }
        }
        longest = max(longest, increase + decrease - 1);
        return make_pair(increase, decrease);
    }
};