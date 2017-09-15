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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prehead = new ListNode(0), *p = prehead;
        prehead->next = head;
        while(p->next) {
            ListNode* header = p;
            p = p->next;
            //check the number of nodes
            ListNode* curNode = p;
            int count = 0;
            while(count++ < k) {
                if(!curNode) {
                    return prehead->next;
                }
                curNode = curNode->next;
            }
            count = 0;
            while(++count < k) {
                ListNode* node = p->next;
                p->next = node->next;
                node->next = header->next;
                header->next = node;
            }
        }
        return prehead->next;
    }
};