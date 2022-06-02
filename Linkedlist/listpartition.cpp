class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* prev=temp;
        ListNode* ll=NULL;
        ListNode* ll1=NULL;
        while(temp!=NULL){
            if(temp->val>=x){
                prev=temp;
                temp=temp->next;
                continue;
            }
            else{
                ListNode* u=temp;
                if(temp==head){
                    prev=temp->next;
                    temp=temp->next;
                    head=temp;
                }
                else{
                    prev->next=temp->next;
                    temp=temp->next;  
                }
                u->next=NULL;
                if(ll==NULL){
                        ll1=u;
                        ll=u;
                }
                else{
                    ll1->next=u;
                    ll1=ll1->next;
                }
            }
        }
        if(ll==NULL) return head;
        if(head==NULL) return ll;
        
        ListNode* head1=ll;
        if(ll!=NULL && head!=NULL){
           while(head1->next!=NULL) head1=head1->next;
        }
        head1->next=head;
        return ll;
    }
};