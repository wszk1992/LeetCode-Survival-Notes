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
    int countNodes(TreeNode* root) {
        int h = 0;
        for(TreeNode* p = root; p != NULL; p = p->left) {
            h++;
        }
        if(h < 2) {
            return h;
        }
        //cout << "h="<<h<<endl;
        int start = 0, end = (1 << (h - 1)) - 1;
        while(start + 1 < end) {
            //cout << "start:"<<start<<", end:"<<end<<endl;
            int mid = (start + end) / 2;
            if(mapToNode(mid, h, root)) {
                start = mid;
            }else {
                end = mid - 1;
            }
        }
        int num = mapToNode(end, h, root) ? end : start;
        num += 1 << (h - 1);
        return num;
    }
    
    TreeNode* mapToNode(int k, int h, TreeNode* root) {
        for(int i = 1 << (h - 2); i > 0; i >>= 1) {
            root = i & k ? root->right : root->left;
        }
        return root;
    }
};