#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
    ListNode **pivot = &head, **prev;
    for (int i=0; i<m; i++)
        pivot = &(*(prev=pivot))->next;
    for (int i=m; i<n; i++) {
        swap(*prev, (*pivot)->next);
        swap(*prev, *pivot);
    }
    return head;
}
};
//recursive
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
};