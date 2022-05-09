#include <bits/stdc++.h>
using namespace std;

/*void combinationUtil(int arr[], int data[],
                     int start, int end,
                     int index, int r);

void printCombination(int arr[], int n, int r)
{

    int data[r];

    combinationUtil(arr, data, 0, n - 1, 0, r);
}

void combinationUtil(int arr[], int data[],
                     int start, int end,
                     int index, int r)
{

    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= end &&
                        end - i + 1 >= r - index;
         i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i + 1,
                        end, index + 1, r);
    }
}
*/
void combinationUtil(int arr[], int n, int r,
                    int index, int data[], int i);
 
// The main function that prints all
// combinations of size r in arr[]
// of size n. This function mainly
// uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
    
    int data[r];
 
    
    combinationUtil(arr, n, r, 0, data, 0);
}
 

void combinationUtil(int arr[], int n, int r,
                    int index, int data[], int i)
{
   
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }
 
    
    if (i >= n)
        return;
 
    
    data[index] = arr[i];
    combinationUtil(arr, n, r, index + 1, data, i + 1);
 
    
    combinationUtil(arr, n, r, index, data, i+1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, n, r);
}