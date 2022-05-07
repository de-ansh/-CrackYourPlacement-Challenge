#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& num) {
        /*set<vector<int>> s;//to get unique triplets
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp;
        temp.resize(3);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(binary_search(nums.begin()+j+1,nums.end(),-nums[i]-nums[j])){
                     temp[0]=nums[i],temp[1]=nums[j],temp[2]=-nums[i]-nums[j];
                    sort(temp.begin(),temp.end());
                    
                    s.insert(temp);
                    }
            }
        vector<vector<int>> ans;
        for(auto triplet: s)
            ans.push_back(triplet);
        return ans;*/
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
}
void display_ans(vector<vector<int>> temp)
{
    for(auto triplet : temp) 
        cout<<triplet[0]<<" "<<triplet[1]<<" "<<triplet[2]<<"\n";
}
int main()
{
    vector<int> v{-1,0,1,2,-1,-4};
    display_ans(threeSum(v));
    return 0;
}