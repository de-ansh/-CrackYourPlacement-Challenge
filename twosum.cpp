#include<bits/stdc++.h>
using namespace std;
vector<int> targetsum(int arr[], int n, int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target)
                return {i,j};
        }
    }
    return {};
}

vector<int> twoSum(int arr[],int n, int target){
    unordered_map<int,int>indices;
    for(int i=0;i<n;i++){
        if(indices.find(target-arr[i])!=indices.end())
            return {indices[target-arr[i]],i};
    }
    return {};
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    for(int &x:twoSum(arr,n,target))
        cout<<x<<" ";
    return 0;
}
