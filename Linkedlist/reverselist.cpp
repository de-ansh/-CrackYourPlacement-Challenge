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