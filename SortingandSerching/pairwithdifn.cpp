// C++ program to find a pair with the given difference
#include <bits/stdc++.h>
using namespace std;

// The function assumes that the array is sorted
bool findPair(int arr[], int size, int n)
{
	int l=0,r=size-1;
	while(l<size && r<size){
		if(arr[r]-arr[l]==n){
			cout<<arr[l]<<","<<arr[r];
			return true;
		}
		i
	}

	cout << "No such pair";
	return false;
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 8, 30, 40, 100};
	int size = sizeof(arr)/sizeof(arr[0]);
	int n = -60;
	findPair(arr, size, n);
	return 0;
}


