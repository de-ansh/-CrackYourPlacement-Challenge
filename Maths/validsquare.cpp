#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> v = {p1, p2, p3, p4};
        set<double> st;
        for (int i = 0; i < 3; i++)
        {
            int x = v[i][0];
            int y = v[i][1];
            for (int j = i + 1; j < 4; j++)
            {
                int x1 = v[j][0];
                int y1 = v[j][1];
                double d = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
                if (d == 0)
                    return false;
                st.insert(d);
            }
        }
        return st.size() == 2;
    }
};