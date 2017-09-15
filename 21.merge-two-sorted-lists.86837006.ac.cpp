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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode(0), *p = prehead;
        ListNode* p1 = l1, *p2 = l2;
        while(p1 || p2) {
            if(p1 == NULL) {
                p->next = p2;
                break;
            }
            if(p2 == NULL) {
                p->next = p1;
                break;
            }
            if(p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        return prehead->next;
    }
};