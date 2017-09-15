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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path=searchPath(root,p);
        vector<TreeNode*> q_path=searchPath(root,q);
        int i;
        for(i=0;i<p_path.size()&&i<q_path.size();i++)
        {
            if(p_path[i]!=q_path[i])
                break;
        }
        if(i==0)
            return NULL;
        else
            return p_path[i-1];
    }
    
    vector<TreeNode*> searchPath(TreeNode* root,TreeNode* target)
    {
        vector<TreeNode*> vec;
        if(root->val==target->val)
        {
            vec.push_back(root);
        }
        else if (root->val>target->val)
        {
            vec=searchPath(root->left,target);
            vec.insert(vec.begin(),root);
        }
        else
        {
            vec=searchPath(root->right,target);
            vec.insert(vec.begin(),root);
        }
        return vec;
    }
};