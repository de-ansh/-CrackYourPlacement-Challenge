#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
        int maxarea=0,l=0,r=height.size()-1;
        while(l<r){
            maxarea=max(maxarea,min(height[l],height[r])* (r-l));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return maxarea;
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for (int i=0;i<n;i++)
        cin>>v[i];
    cout<<maxArea(v);
}