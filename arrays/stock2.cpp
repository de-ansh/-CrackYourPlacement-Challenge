#include<bits/stdc++.h>
using namespace std;
int stock_two(int arr[],int n){
    int curhold=INT_MIN,curNotHold=0;
    for(int i=0;i<n;i++){
        int prevHold=curhold,prevNotHold=curNotHold;
        curhold=max(prevHold,prevNotHold-arr[i]);
        curNotHold=max(prevNotHold,prevHold+arr[i]);

    }
    return curNotHold;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<stock_two(arr,n);
}