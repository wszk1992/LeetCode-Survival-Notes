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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* p1 = prehead, *p2;
        for(int i = 0; i < m - 1; i++) {
            p1 = p1->next;
        }
        p2 = p1->next;
        for(int i = m; i < n; i++) {
            switchListNode(p1, p2);
        }
        return prehead->next;
        
    }
    
    void switchListNode(ListNode* p1, ListNode* p2) {
        ListNode* temp = p1->next;
        p1->next = p2->next;
        p2->next = p2->next->next;
        p1->next->next = temp;
    }
};