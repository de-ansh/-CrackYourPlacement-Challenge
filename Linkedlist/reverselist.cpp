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
//iterative
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
};