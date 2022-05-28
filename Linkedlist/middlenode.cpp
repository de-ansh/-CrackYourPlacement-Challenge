#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode *temp = head;
        int length=0;
				
        while(temp){
            length++;
            temp = temp->next;
        }
        int middle = length/2;
        temp=head;
       
        while(temp && middle--)
            temp=temp->next;
        
        return temp;
    }
};