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
        ListNode *head;
        int len1 = lenthOfList(l1);
        int len2 = lenthOfList(l2);
        pair<int, ListNode*> p = helper(l1, len1, l2, len2, max(len1, len2));
        if(p.first) {
            head = new ListNode(p.first);
            head->next = p.second;
        } else {
            head = p.second;
        }
        return head;
    }
    
    pair<int, ListNode*> helper(ListNode* l1, int& len1, ListNode* l2, int& len2, int i) {
        if(i == 0) {
            ListNode* node = NULL;
            return make_pair(0, node);
        }
        pair<int, ListNode*> p = helper(i <= len1 ? l1->next : l1, len1, i <= len2 ? l2->next : l2, len2, i - 1);
        int sum = (i <= len1 ? l1->val : 0) + (i <= len2 ? l2->val : 0) + p.first;
        ListNode* node = new ListNode(sum % 10);
        node->next = p.second;
        return make_pair(sum / 10, node);
    }
    
    int lenthOfList(ListNode* l) {
        int num = 0;
        while(l) {
            num++;
            l = l->next;
        }
        return num;
    }
};