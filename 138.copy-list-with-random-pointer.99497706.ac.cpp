/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        //map from old node to new node
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode* dummy = new RandomListNode(0), *p_new = dummy, *p_old = head;
        while(p_old) {
            p_new->next = new RandomListNode(p_old->label);
            map[p_old] = p_new->next;
            p_new = p_new->next;
            p_old = p_old->next;
        }
        p_new = dummy;
        p_old = head;
        while(p_old) {
            p_new->next->random = map[p_old->random];
            p_new = p_new->next;
            p_old = p_old->next;
        }
        return dummy->next;
    }
};