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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int node_num=0;
        ListNode* Node = NULL;
        //calculate num of node;
        for(Node = head;Node!=NULL;Node=Node->next)
        {
            node_num++;
        }
        
        if(node_num==n)
        {
            head=head->next;
        }
        else
        {
            int i=node_num-n-1;
            //to num-n-1 node;
            for(Node = head;i>0;Node=Node->next)
            {
                i--;
            }
            Node->next = Node->next->next;
        }
        return head;
        
    }
};