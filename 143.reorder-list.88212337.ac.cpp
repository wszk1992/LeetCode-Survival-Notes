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
    void reorderList(ListNode* head) {
        if(head == NULL) {
            return;
        }
        ListNode prehead(0), *p1 = &prehead, *p2 = &prehead;
        prehead.next = head;
        while(p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* backList = reverseList(p1->next);
        p1->next = NULL;
        mergeList(head, backList);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode prehead(0), *p = &prehead, *pEnd = head;
        prehead.next = head;
        while(pEnd && pEnd->next) {
            ListNode* temp = p->next;
            p->next = pEnd->next;
            pEnd->next = pEnd->next->next;
            p->next->next = temp;
        }
        return p->next;
    }
    
    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        while(p1 && p2) {
            ListNode* p1Next = p1->next;
            ListNode* p2Next = p2->next;
            p1->next = p2;
            p2->next = p1Next;
            p1 = p1Next;
            p2 = p2Next;
        }
    }
};