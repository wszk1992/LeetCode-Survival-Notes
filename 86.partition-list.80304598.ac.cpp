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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prehead = new ListNode(0), *p1 = prehead, *p = prehead;
        prehead->next = head;
        ListNode *prehead2 = new ListNode(0), *p2 = prehead2;
        while(p->next) {
            if(p->next->val < x) {
                p1->next = p->next;
                p1 = p1->next;
            }else {
                p2->next = p->next;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = prehead2->next;
        p2->next = NULL;
        return prehead->next;
    }
};