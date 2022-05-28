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