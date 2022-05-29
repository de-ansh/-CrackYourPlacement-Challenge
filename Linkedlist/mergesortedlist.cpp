#include <bits/stdc++.h>
using namespace std;
//iteratuve approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode *dummy=new ListNode (-101);
        ListNode *head=dummy;
        while(list1!= NULL && list2!=NULL){
            if(list1->val<list2->val){
                ListNode *newnode=new ListNode (list1->val);
                dummy->next=newnode;
                list1=list1->next;
            }
            else{
                ListNode *newNode=new ListNode (list2->val);
                dummy->next=newNode;
                list2=list2->next;
            }
            dummy=dummy->next;
        }
        if(list1!=NULL) dummy->next=list1;
        if(list2!=NULL) dummy->next=list2;
        return head->next;
    }
};
//recursive 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
       
        
            if(list1->val<=list2->val){
                list1->next=mergeTwoLists(list1->next,list2);
                return list1;
            }
            else{
                list2->next=mergeTwoLists(list1,list2->next);
                return list2;
            }
    }
};