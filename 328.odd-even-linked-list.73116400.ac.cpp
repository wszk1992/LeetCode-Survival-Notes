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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* p1 = new ListNode(0), *p = p1, *p1Head = p1;
        ListNode* p2 = new ListNode(0), *p2Head = p2;
        p1->next = head;
        bool isOdd = 1;
        while(p->next) {
            if(isOdd) {
                p1->next = p->next;
                p1 = p1->next;
            }else {
                p2->next = p->next;
                p2 = p2->next;
            }
            isOdd = !isOdd;
            p = p->next;
        }
        p1->next = p2Head->next;
        p2->next = NULL;
        return p1Head->next;
    }
};