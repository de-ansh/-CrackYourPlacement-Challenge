#include<bits/stdc++.h>
using namespace std;
//1st Approah
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy= new ListNode(101);
        dummy->next=head;
        ListNode *curr=head;
        ListNode *prev=dummy;
        while(curr!=NULL){
            if(curr->val==prev->val){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};
//2nd Appraoch
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *curr= head;
        while(curr->next!=NULL){
            if(curr->val==curr->next->val){
                curr->next=curr->next->next;
            }
            else
                curr=curr->next;
        }
        return head;
    }
};