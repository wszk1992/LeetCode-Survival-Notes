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
        if(head==NULL)
            return head;
        else if (head->next == NULL)
            return head;
        else{
            ListNode* p1=head;
            ListNode* p2=head->next;
            ListNode* temp;
            for(;;){
                if(p1->val!=p2->val){
                    p1 = p1->next;
                    p2 = p2->next;
                }
                else{
                    temp = p2;
                    p2 = p2->next;
                    free(temp);
                    p1->next = p2;
                }
                if(p2==NULL)
                    break;
            }
            return head;   
        }
        
    }
};

//can use only 1 pointer