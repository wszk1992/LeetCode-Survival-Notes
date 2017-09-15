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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            if(st.top()->left) {
                st.push(st.top()->left);
            } else {
                while(!st.top()->right) {
                    count++;
                    if(count == k) {
                        return st.top()->val;
                    }
                    st.pop();
                }
                TreeNode* r = st.top()->right;
                count++;
                if(count == k) {
                    return st.top()->val;
                }
                st.pop();
                st.push(r);
            }
        }
        return -1;
    }
};