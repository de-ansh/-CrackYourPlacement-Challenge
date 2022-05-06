#include<bits/stdc++.h>
using namespace std;
int findMinDiff(int arr[], int n, int m){
    sort(arr, arr+n);
    int ans=INT_MAX;
    for(int i=0;i+m-1<n;i++)
        ans=min(ans,arr[i+m-1]-arr[i]);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<findMinDiff(a,n,m);

    return 0;
}
