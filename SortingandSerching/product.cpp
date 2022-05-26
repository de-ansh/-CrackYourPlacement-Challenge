#include <bits/stdc++.h>
using namespace std;
void product(int arr[],int n){
	if(n==1){
		cout<<0<<"\n";
		return;
	}
	int left[n];
	int right[n];
	int product[n];
	left[0]=1; right[n-1]=1;
	for (int i = 1; i < n; i++)
        left[i] = arr[i - 1] * left[i - 1];
    for (int j = n - 2; j >= 0; j--)
        right[j] = arr[j + 1] * right[j + 1];
    for (int i = 0; i < n; i++)
        product[i] = left[i] * right[i];
    sort(product,product+n);
    for (int i = 0; i < n; i++)
        cout << product[i] << " ";
    return;

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	product(arr,n);
	return 0;
}