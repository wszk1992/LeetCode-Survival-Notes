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
//bottom-up merge sort
    ListNode* sortList(ListNode* head) {
        if(!head) {
            return NULL;
        }
        int len = 0;
        ListNode* prehead = new ListNode(0), *p = prehead;
        prehead->next = head;
        while(p->next) {
            p = p->next;
            len++;
        }
        for(int step = 1; step < len; step <<= 1) {
            //display(prehead->next);
            ListNode* cur = prehead->next;
            ListNode* tail = prehead;
            while(cur) {
                ListNode* left = cur;
                ListNode* right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        //display(prehead->next);
        return prehead->next;
    }
    
    ListNode* split(ListNode* start, int n) {
        if(!start) {
            return NULL;
        }
        ListNode* cur = start;
        ListNode* res;
        while(--n && cur->next) {
            cur = cur->next;
        }
        res = cur->next;
        cur->next = NULL;
        return res;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* tail) {
        //display(l1);cout<<"merge with"<<endl;display(l2);
        ListNode* p = tail;
        while(l1 || l2) {
            if(!l2 || (l1 && l1->val < l2->val)) {
                p->next = l1;
                l1 = l1->next;
            }else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        return p;
    }
    
    void display(ListNode* l) {
        cout<<"[";
        while(l) {
            cout << l->val <<" ";
            l = l->next;
        }
        cout << "]"<<endl;
    }
};
