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
    ListNode* removeElements(ListNode* head, int val) {
        //sudohead -----> head  ; introduce sudohead to reduce code lines
        ListNode* sudohead = new ListNode(0);
        sudohead->next = head;
        ListNode* p = sudohead;
        ListNode* temp;
        while(p->next!=NULL)
        {
            //if the next node is the element, link to the node next to it and free it
            if(p->next->val == val)
            {
                temp = p->next;
                p->next = temp->next;
                free(temp);
            }
            else
                p=p->next;
        }
        return sudohead->next;
    }
};

//try to use recursive