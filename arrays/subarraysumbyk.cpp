#include<bits/stdc++.h>
using namespace std;
int subarraycount(int arr[],int n,int k){
    vector<int>count(k);
    count[0]=1;
    int prefix=0,res=0;
    for(int i=0;i<n;i++){
        prefix=(prefix+arr[i]%k+k)%k;
        res+= count[prefix]++;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<subarraycount(arr,n,k);    
    return 0;
}
