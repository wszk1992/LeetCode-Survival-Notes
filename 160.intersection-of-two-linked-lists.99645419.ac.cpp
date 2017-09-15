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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            return NULL;
        }
        //connect the last node with headA
        ListNode *p = headA;
        while(p->next) {
            p = p->next;
        }
        p->next = headA;
        
        //find the entry of the circle, slow&fast pointer
        ListNode *dummy = new ListNode(0);
        dummy->next = headB;
        ListNode *p1 = headB, *p2 = headB->next;
        while(p2 && p2->next) {
            if(p1 == p2) {
                break;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if(p1 != p2) {
            p->next = NULL;
            return NULL;
        }
        p1 = dummy;
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p->next = NULL;
        return p1;
    }
};