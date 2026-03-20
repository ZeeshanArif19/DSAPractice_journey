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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy; //moving pointer to append the next node
        auto cmp=[&](ListNode* &a,ListNode* &b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> pq(cmp);

        for(ListNode* &head:lists){
            if(head!=nullptr) pq.push(head);
        }
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            
            tail->next=node;
            tail=tail->next;
            if(node->next!=nullptr) pq.push(node->next);
        }
        return dummy->next;
    }
};