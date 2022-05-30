class Solution {
private:
    ListNode *reverseList(ListNode *head){
        ListNode *prev=NULL;
        ListNode *curr= head;
        ListNode *temp=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode *dummy;
        ListNode *head;
        dummy =head= new ListNode(-1);
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int carry=0;
        while(l1||l2){
            int firstval= l1?l1->val:0;
            int secondval=l2?l2->val:0;
            int total= firstval+secondval+carry;
            carry=total/10;
            total=total%10;
            ListNode *newNode = new ListNode(total);
            dummy->next=newNode;
            dummy=dummy->next;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        if(carry)
            dummy->next= new ListNode(1);
        return reverseList(head->next);
    }
};