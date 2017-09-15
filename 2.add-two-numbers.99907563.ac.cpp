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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *p = dummy;
        ListNode* p1 = l1, *p2 = l2;
        int carry = 0;
        while(p1 || p2 || carry) {
            int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
            p1 = p1 ? p1->next : p1;
            p2 = p2 ? p2->next : p2;
            p = p->next;
        }
        return dummy->next;
    }
};