#include <bits/stdc++.h>
using namespace std;
//Appraoch 1
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num=head->val;
        while(head->next!=NULL){
            num=num*2+head->next->val;
            head=head->next;
        }
        return num;
    }
};
//2nd Approach
//we will use bit manupulation
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num=head->val;
        while(head->next!=NULL){
            num=(num<<1)|head->next->val;
            head=head->next;
        }
        return num;
    }
};