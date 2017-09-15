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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }
        map<int, vector<int>> map;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
               	pair<TreeNode*, int> p = q.front();
                map[p.second].push_back(p.first->val);
                if(p.first->left) {
                    q.push(make_pair(p.first->left, p.second - 1));
                }
                if(p.first->right) {
                    q.push(make_pair(p.first->right, p.second + 1));
                }
                q.pop();
            }
        }
        for(auto pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }

};