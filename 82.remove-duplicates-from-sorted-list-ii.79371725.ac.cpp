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
    ListNode* deleteDuplicates(ListNode* head) {
        //two mode: 1. remove mode 2. no-remove mode
        //if(next node == next next node)  {if(remove mode)}
        bool remove = 0;
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* p = prehead;
        while(p->next) {
            if(p->next->next != NULL && p->next->val == p->next->next->val) {
                ListNode* temp = p->next;
                p->next = p->next->next;
                //cout<<"remove:" << temp->val << endl;
                delete temp;
                remove = 1;
            }else {
                if(remove) {
                    ListNode* temp = p->next;
                    p->next = p->next->next;
                    //cout<<"remove:" << temp->val << endl;
                    delete temp;
                    remove = 0;
                }else {
                    p = p->next;
                }
            }
            
        }
        return prehead->next;
    }
};