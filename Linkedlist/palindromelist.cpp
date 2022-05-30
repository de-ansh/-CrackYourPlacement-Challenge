#include <bits/stdc++.h>
using namespace std;
//using recursive reverseList
class Solution {
public:
    ListNode *helper(ListNode *curr, ListNode*prev){
        if(curr==NULL)
            return prev;
        ListNode *newnode= curr->next;
        curr->next=prev;
        return helper(newnode,curr); 
    }
    ListNode* reverseList(ListNode* head) {
        return helper(head,NULL);
    }
   
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL &&fast->next->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        slow->next=reverseList(slow->next);
        ListNode* start=head, *mid=slow->next;
        while(mid!=NULL){
            if(mid->val!=start->val) return false;
            start= start->next;
            mid=mid->next;
        }
        slow->next=reverseList(slow->next);
        return true;
    }
};

//iterative revserList
class Solution {
public:

    
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head,*prev=NULL,*temp;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;

        }
        return prev;
    }
   
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL &&fast->next->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        slow->next=reverseList(slow->next);
        ListNode* start=head, *mid=slow->next;
        while(mid!=NULL){
            if(mid->val!=start->val) return false;
            start= start->next;
            mid=mid->next;
        }
        slow->next=reverseList(slow->next);
        return true;
    }
};