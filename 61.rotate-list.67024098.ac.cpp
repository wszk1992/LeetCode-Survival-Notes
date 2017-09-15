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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *prehead = new ListNode(0), *p1 = prehead, *p2 = prehead, *p = prehead;
        prehead->next = head;
        int num = 0;
        while(p->next) {
            p = p->next;
            num++;
        }
        if((k = k % num) == 0) {
            return head;
        }
        while(k--) {
            p2 = p2->next;
        }
        while(p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        prehead->next = p1->next;
        p2->next = head;
        p1->next = NULL;
        return prehead->next;
    }
};