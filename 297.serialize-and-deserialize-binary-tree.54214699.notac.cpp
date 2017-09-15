/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(!root)
            return s;
        vector<TreeNode*> old_node;
        vector<TreeNode*> new_node;
        old_node.push_back(root);
        bool flag=1;
        while(flag)
        {
            flag = 0;
            for(int i=0;i<old_node.size();i++)
            {
                if(old_node[i])
                {
                    flag=1;
                    s.push_back(old_node[i]->val+'0');
                    new_node.push_back(old_node[i]->left);
                    new_node.push_back(old_node[i]->right);
                }
                else
                {
                    s.push_back(0);
                }
            }
            old_node=new_node;
            new_node.clear();
        }
        //one line with all NULL!    e.g  for [1,2,3] , s will be [1,2,3,NULL,NULL,NULL,NULL];
        for(int i=s.length()-1;i>=0;i--)
            if(s[i]==0)
                s.erase(i);
            else break;
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        TreeNode* root=new TreeNode(data[0]-'0');
        vector<TreeNode*> old_vec;
        vector<TreeNode*> new_vec;
        old_vec.push_back(root);
        int i=1;
        while(i<data.length())
        {
             for(int j=0;j<old_vec.size();j++)
             {
                 if(i>=data.length()||data[i]==0)
                    old_vec[j]->left = NULL;
                 else
                 {
                    old_vec[j]->left = new TreeNode(data[i]-'0');
                    new_vec.push_back(old_vec[j]->left);
                 }
                 i++;
                 if(i>=data.length()||data[i]==0)
                    old_vec[j]->right = NULL;
                 else
                 {
                    old_vec[j]->right = new TreeNode(data[i]-'0');
                    new_vec.push_back(old_vec[j]->right);
                 }
                 i++;
             }
             old_vec = new_vec;
             new_vec.clear();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));