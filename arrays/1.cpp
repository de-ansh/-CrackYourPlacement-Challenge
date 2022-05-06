#include<bits/stdc++.h>
using namespace std;
//brute force TC O(nlogn) & sc O(logn)
/*int findDuplicate(int arr[], int n){
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])
            return arr[i];
    }
    return -1;
}*/
//2nd TC O(n), Sc O(n)
/*int findDuplicate(int arr[], int n){
    unordered_set<int> seen;
    for(int i=0;i<n;i++){
        if(seen.count(arr[i]))
            return arr[i];
        seen.insert(arr[i]);
    }
    return -1;
}*/
//3rd TC O(nlogn) SC O(1) 
int findDuplicate(int arr[], int n){
    auto small_or_equal = [&](int cur) {
            int count = 0;
            for (int i=1;i<n;i++) {
                if (arr[i] <= cur)
                    count++;
            }
            return count;
        };
         int low = 1, high = n;
        int duplicate = -1;
        while (low <= high) {
            int cur = (low + high) / 2;
            
            if (small_or_equal(cur) > cur) { 
                duplicate = cur;
                high = cur - 1;
            } else {
                low = cur + 1;
            }
        }

        return duplicate;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findDuplicate(arr,n);
    return 0;

}