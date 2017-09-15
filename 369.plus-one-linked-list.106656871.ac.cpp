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
    ListNode* plusOne(ListNode* head) {
        ListNode* rvHead = reverseList(head);
        ListNode* dummy = new ListNode(0), *p = dummy;
        dummy->next = rvHead;
        int carry = 1;
        while(p->next) {
            int sum = p->next->val + carry;
            if(sum < 10) {
                p->next->val = sum;
                carry = 0;
                break;
            } else {
                p->next->val = 0;
            }
            p = p->next;
        }
        if(carry) {
            p->next = new ListNode(1);
        }
        return reverseList(dummy->next);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = head;
        while(p->next) {
            ListNode* temp = dummy->next;
            dummy->next = p->next;
            p->next = p->next->next;
            dummy->next->next = temp;
        }
        return dummy->next;
    }
};