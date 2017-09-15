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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1, vector<TreeNode*>()));
        return generateHelper(1, n, dp);
    }
    
    vector<TreeNode*> generateHelper(int start, int end, vector<vector<vector<TreeNode*>>>& dp) {
        if(start > end) {
            return vector<TreeNode*>();
        }
        if(!dp[start][end].empty()) {
            return dp[start][end];
        }
        vector<TreeNode*> res;
        for(int k = start; k <= end; k++) {
            // cout << "k=" << k << endl;
            // cout << start << "---" << end << endl;
            vector<TreeNode*> leftTrees = generateHelper(start, k - 1, dp);
            vector<TreeNode*> rightTrees = generateHelper(k + 1, end, dp);
            if(leftTrees.empty() && rightTrees.empty()) {
                res.push_back(new TreeNode(k));
            }else if(leftTrees.empty()) {
                for(auto tree : rightTrees) {
                    TreeNode* node = new TreeNode(k);
                    node->right = tree;
                    res.push_back(node);
                }
            }else if(rightTrees.empty()) {
                for(auto tree : leftTrees) {
                    TreeNode* node = new TreeNode(k);
                    node->left = tree;
                    res.push_back(node);
                }
            }else {
                for(auto leftTree: leftTrees) {
                    for(auto rightTree : rightTrees) {
                        TreeNode* node = new TreeNode(k);
                        node->left = leftTree;
                        node->right = rightTree;
                        res.push_back(node);
                    }
                }
            }
        }
        dp[start][end] = res;
        return res;
    }
};