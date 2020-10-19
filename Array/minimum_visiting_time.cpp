//Suppose there are some points given as an array. We have to find the minimum time in seconds to visit all points. There are some conditions.

//In one second, it can move vertically, horizontally and diagonally
//We have to visit the points in the same order as they appear in the array.
//So if the points are [(1, 1), (3, 4), (-1, 0)], then output will be 7. If we check the sequence for the shortest route,
//the sequence will be (1, 1), (2, 2), (3, 3), (3, 4), (2, 3), (1, 2), (0, 1), (-1, 0)

//To solve this we will just find the maximum of x coordinate difference of two consecutive points,
//and y coordinate difference of two consecutive points. The max values will be added together.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &p)
    {
        int ans = 0;
        int n = p.size();
        for (int i = 1; i < n; i++)
        {
            ans += max(abs(p[i][0] - p[i - 1][0]), abs(p[i][1] - p[i - 1][1]));
        }
        return ans;
    }
};
main()
{
    Solution ob;
    vector<vector<int>> c = {{1, 1}, {3, 4}, {-1, 0}};
    cout << ob.minTimeToVisitAllPoints(c);
}