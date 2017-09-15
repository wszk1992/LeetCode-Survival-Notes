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
    ListNode *detectCycle(ListNode *head) {
        if(!head) {
            return NULL;
        }
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode *p1 = head, *p2 = head->next;
        while(p2 && p2->next) {
            if(p1 == p2) {
                break;
            }else {
                p1 = p1->next;
                p2 = p2->next->next;
            }
        }
        if(p2 == NULL || p2->next == NULL) {
            return NULL;
        }else {
            while(prehead != p1) {
                prehead = prehead->next;
                p1 = p1->next;
            }
            return p1;
        }
    }
};