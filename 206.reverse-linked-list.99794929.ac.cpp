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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        reverse(dummy);
        return dummy->next;
    }
    
    ListNode* reverse(ListNode* prev) {
        if(prev->next == NULL) {
            return NULL;
        }
        ListNode* lastNode = reverse(prev->next);
        if(lastNode) {
            lastNode->next = prev->next;
            prev->next = prev->next->next;
            lastNode->next->next = NULL;
            return lastNode->next;
        } else {
            return prev->next;
        }
    }
};