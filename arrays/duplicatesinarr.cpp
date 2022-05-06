#include<bits/stdc++.h>
using namespace std;
vector<int>duplicate(int arr[],int n){
    vector<int>ans;
    /*sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])
            ans.push_back(arr[i]);
    }*/
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++)
        freq[arr[i]]++;
    for(auto it:freq)
        if(it.second>=2)
            ans.push_back(it.first);
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int &x:duplicate(arr,n))
        cout<<x<<" ";
    return 0;
}
