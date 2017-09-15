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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* p1 = head;
        ListNode* p2 = reverseList(slow->next);
        while(p2) {
            if(p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = head;
        while(p->next) {
            ListNode* temp = p->next;
            p->next = temp->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    }
};