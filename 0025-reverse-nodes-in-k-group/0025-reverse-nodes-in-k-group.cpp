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
    bool canMove(ListNode* node,int k){
        for(int i=0;i<k;i++){
            if(node==nullptr) return false;
            node=node->next;
        }
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        bool move=canMove(head,k);
        ListNode* prevGrouptail=dummy;
        ListNode* curr=head;

        while(move){
            ListNode* groupStart=curr;
            ListNode* prev=nullptr;
            for(int i=0;i<k;i++){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            move=canMove(curr,k);

            groupStart->next=curr;
            prevGrouptail->next=prev;
            prevGrouptail=groupStart;
        }
        ListNode* newHead=dummy->next;
        delete dummy;
        return newHead;
    }
};