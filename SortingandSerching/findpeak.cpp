#include <bits/stdc++.h>
using namespace std;
int search(vector<int>&nums, int l, int r){
        if(l==r)
            return l;
        int mid=(l+r)/2;
        if(nums[mid]>nums[mid+1])
            return search(nums,l,mid);
        return search(nums,mid+1,r);
        
    }
 int findPeakElement(vector<int>& nums) {
    return search(nums,0,nums.size()-1);
 }
 int main(int argc, char const *argv[])
 {
 	int n;
 	cin>>n;
 	std::vector<int> v(n);
 	for (int i = 0; i < n; ++i)
 	{
 		int k;
 		cin>>k;
 		v.push_back(k);
 	}
 	cout<<findPeakElement(v);
 	return 0;
 }