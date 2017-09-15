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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* p = prehead;
        while(p && p->next) {
            ListNode* node = prehead;
            while(node != p) {
                if(p->next->val < node->next->val) {
                    ListNode* temp = p->next;
                    p->next = p->next->next;
                    temp->next = node->next;
                    node->next = temp;
                    break;
                }
                node = node->next;
            }
            if(node == p) {
                p = p->next;
            }
        }
        return prehead->next;
    }
};