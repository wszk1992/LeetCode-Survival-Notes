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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* header = new ListNode(0);
        ListNode* p = header;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto list : lists) {
            if(list) {
                q.push(list);
            }
        }
        while(!q.empty()) {
            p->next = q.top();
            if(q.top()->next != NULL) {
                q.push(q.top()->next);
            }
            q.pop();
            p = p->next;
        }
        return header->next;
    }
};