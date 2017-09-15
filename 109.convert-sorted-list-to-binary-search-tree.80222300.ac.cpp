/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root;
        vector<int> list;
        while(head) {
            list.push_back(head->val);
            head = head->next;
        }
        return buildBST(list, 0, list.size());
    }
    
    TreeNode* buildBST(vector<int>& list, int start, int end) {
        if(start == end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(list[mid]);
        root->left = buildBST(list, start, mid);
        root->right = buildBST(list, mid + 1, end);
        return root;
    }
    
};