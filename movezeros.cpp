#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int lnat = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[lnat++] = nums[i];
            }
        }
        for (int i = lnat; i < nums.size(); i++)
            nums[i] = 0;
    }
};