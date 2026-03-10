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
    ListNode* partition(ListNode* head, int x) {
        ListNode* Ghead=new ListNode(-1);
        ListNode* Gtail=Ghead;
        ListNode* Lhead=new ListNode(-1);
        ListNode* Ltail=Lhead;
        ListNode* temp=head;

        while(temp){
            if(temp->val<x){
                Ltail->next=temp;
                Ltail=Ltail->next;
            }
            else{
                Gtail->next=temp;
                Gtail=Gtail->next;
            }
            temp=temp->next;
        }
        Gtail->next=NULL;
        Ltail->next=Ghead->next;

        ListNode* res=Lhead->next;
        delete Ghead;
        delete Lhead;
        return res;
    }
};