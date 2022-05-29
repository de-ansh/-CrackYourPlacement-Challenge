#include<bits/stdc++.h>
using namespace std;
//iterative
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
            return head;
        
        ListNode *prev, *curr = head;
        
        while(curr!=NULL){
            if(curr->val == val){
                if(prev==NULL){
                    head = curr->next;
                    curr = head;
                }
                else{
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        
        
        return head;
        
    }
};
//Recursive
class solution
{
public:
     ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
         head->next = removeElements(head->next, val);
        return head->val==val?head->next:head;
     }
    
};