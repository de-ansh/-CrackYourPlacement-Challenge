#include<bits/stdc++.h>
using namespace std;
bool permute(int arr[], int brr[],int n,int k){
    sort(arr,arr+n);
    sort(brr,brr+n,greater<int>());
    for (int i = 0; i < n; i++)
    {
        if(arr[i]+brr[i]<k)
            return false;
    }
    return true;
    
}
int main(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
        cin>>brr[i];
    int k;
    cin>>k;
    cout<<permute(arr,brr,n,k);
    
    return 0;
    
}