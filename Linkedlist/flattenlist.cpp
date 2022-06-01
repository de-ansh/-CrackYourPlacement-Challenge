class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node *curr=head;
        while(curr){
            Node * flattened=flatten(curr->child);
            curr->child=NULL;
            if(flattened == NULL){
                curr = curr->next;
            }else{
                Node *nxt=curr->next;
                curr->next=flattened;
                flattened->prev=curr;
                while(flattened->next){
                    flattened=flattened->next;
                }
                flattened->next=nxt;
                if(nxt)
                    nxt->prev=flattened;
                curr=nxt;
            }
        }
        return head;
    }
};