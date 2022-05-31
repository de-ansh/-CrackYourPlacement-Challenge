class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head)
        {
            auto nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
    
    ListNode* midNode(ListNode* head)
    {
        auto slow = head, fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    void reorderList(ListNode* head) {
        //First finding the middle node
        if(!head || !head->next) return;
        
        auto mid = midNode(head);
        
        auto R = reverseList(mid), L = head->next;
        
        for(int i=0; L!=R; i++, head=head->next)
        {
            if(i%2)
            {
                head->next = L;
                L = L->next;
            }
            else
            {
                head->next = R;
                R = R->next;
            }
        }
        
    }
};