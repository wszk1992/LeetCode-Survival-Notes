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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        //build next stack
        stack<TreeNode*> next;
        TreeNode* p = root;
        while(p) {
            if(target < p->val) {
                next.push(p);
                p = p->left;
            } else {
                p = p->right;
            }
        }
        //first node larger than target
        TreeNode* r = next.empty() ? NULL : next.top(); 
        
        //build last stack
        stack<TreeNode*> last;
        p = root;
        while(p) {
            if(target < p->val) {
                p = p->left;
            } else {
                last.push(p);
                p = p->right;
            }
        }
        //first node smaller than target
        TreeNode* l = last.empty() ? NULL : last.top();
        
        vector<int> values;
        while(k--) {
            double diff_l = l ? target - l->val : numeric_limits<double>::max();
            double diff_r = r ? r->val - target : numeric_limits<double>::max();
            // cout << l->val << "," << r->val <<endl;
            if(diff_l < diff_r) {
                values.push_back(l->val);
                l = lastNode(last);
            } else {
                values.push_back(r->val);
                r = nextNode(next);
            }
        }
        return values;
    }
    
    TreeNode* nextNode(stack<TreeNode*>& next) {
        if(next.empty()) {
            return NULL;
        }
        if(!next.top()->right) {
            next.pop();
        } else {
            TreeNode* p = next.top()->right;
            next.pop();
            while(p) {
                next.push(p);
                p = p->left;
            }
        }
        return next.empty() ? NULL : next.top();
    }
    
    TreeNode* lastNode(stack<TreeNode*>& last) {
        if(last.empty()) {
            return NULL;
        }
        if(!last.top()->left) {
            last.pop();
        } else {
            TreeNode* p = last.top()->left;
            last.pop();
            while(p) {
                last.push(p);
                p = p->right;
            }
        }
        return last.empty() ? NULL : last.top();
    }
};