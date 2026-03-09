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
    ListNode* reverse(ListNode* node,int count){
        ListNode* prev=nullptr;
        ListNode* curr=node;
        while(count-- && curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        node->next=curr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right) return head;
        ListNode dummy(0);
        //if left=1 then prev will be nullptr after loop so we use dummynode
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* curr=head;

        for(int i=1;i<left;i++){
            prev=curr;
            curr=curr->next;
        }

        ListNode* newHead=reverse(curr,right-left+1);
        prev->next=newHead;
        return dummy.next;
    }
};