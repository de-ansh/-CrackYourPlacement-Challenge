#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        int nums[n];
        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                nums[j] = i;
                j++;
            }
        }
        if (j < k)
        {
            return -1;
        }
        return nums[k - 1];
    }
};