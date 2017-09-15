/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct Mode {
    vector<int> mode_list;
    int freq;
    Mode(): freq(0) {}
};
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        Mode m;
        int curVal = 0;
        int curFreq = 0;
        inorderTraverse(root, m, curVal, curFreq);
        return m.mode_list;
    }

    void inorderTraverse(TreeNode* root, Mode& m, int& curVal, int& curFreq) {
        if(root == NULL) {
            return;
        }
        inorderTraverse(root->left, m, curVal, curFreq);
        if(curFreq == 0) {
            curVal = root->val;
        }
        if(root->val == curVal) {
            curFreq++;
        } else {
            curVal = root->val;
            curFreq = 1;
        }
        if(curFreq == m.freq) {
            m.mode_list.push_back(root->val);
        } else if(curFreq > m.freq) {
            m.mode_list = vector<int>(1, root->val);
            m.freq = curFreq;
        }
        inorderTraverse(root->right, m, curVal, curFreq);
    }
};