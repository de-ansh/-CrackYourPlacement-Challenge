#include<bits/stdc++.h>
using namespace std;
//twoPiointer approach
class Solution {
public:
    vector<vector<int>>twosum(vector<int>&nums,int target,int start){
        vector<vector<int>>res;
        int lo=start,hi=nums.size()-1;
        while(lo<hi){
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
                ++lo;
            } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                --hi;
            } else {
                res.push_back({ nums[lo++], nums[hi--] });
            }
        }
        return res;
    }
    vector<vector<int>> ksum(vector<int> &nums,int target,int start,int k){
        vector<vector<int>>res;
        if(start==nums.size()) return res;
        int avg_val=target/k;
        if(nums[start]>avg_val || avg_val>nums.back()) return res;
        if(k==2)
            return twosum(nums,target,start);
        for(int i=start;i<nums.size();i++){
            if(i==start || nums[i-1]!=nums[i]){
                for (vector<int>& subset : ksum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return ksum(nums,target,0,4);
    }
};


//2 pointer interative 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int> > res;
        
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
            
    }
};

//3 pointer and binary_search
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                     int x=target-nums[i]-nums[j]-nums[k];
                    if(binary_search(nums.begin()+k+1,nums.end(),x)){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(x);
                        s.insert(temp);
                    }
                }
                   
                
            }
        }
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
            
    }