class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        //started merging from picking up minimum element
        int ans=0;
        while(arr.size()>1){
            int idx= min_element(arr.begin(),arr.end())- arr.begin();//minimum element's idx
            if(idx== arr.size()-1){
                ans+= arr[idx]*arr[idx-1];
            }
            else if(idx==0){
                ans+= arr[idx]*arr[idx+1];
            }
            else{
                ans+= arr[idx]*min(arr[idx-1], arr[idx+1]);
            }
            arr.erase(arr.begin()+idx);
        }
        return ans;
    }
};