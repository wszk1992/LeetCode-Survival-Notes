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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        for(ListNode* p = prehead; p && p->next; p = p->next->next) {
            swapTwoNodes(p);
        }
        return prehead->next;
    }
    
    void swapTwoNodes(ListNode* prehead) {
        if(prehead->next->next) {
            ListNode* first = prehead->next;
            prehead->next = first->next;
            first->next = first->next->next;
            prehead->next->next = first;
        }
    }
};