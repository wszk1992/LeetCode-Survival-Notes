/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //1:replace the node->val with the next node->val 
        node->val = node->next->val;
        //2:link the node with the next next node
        node->next = node->next->next;
    }
};