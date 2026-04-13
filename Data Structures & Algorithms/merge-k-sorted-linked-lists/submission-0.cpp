/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        ListNode* head = new ListNode();
        ListNode* dummy = head;
        for(auto &x:lists){
            q.push(x);
        }
        while(!q.empty()){
            ListNode* top = q.top();
            q.pop();
            if(top->next) q.push(top->next);
            dummy->next = top;
            dummy = dummy->next;
        }
        return head->next;
    }
};
