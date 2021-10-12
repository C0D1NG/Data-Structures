// #13 - [https://leetcode.com/problems/merge-intervals/]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){return a[0]<b[0];});
        
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> temp = intervals[0];
        for(int i=1; i<n; i++){
            if(temp[1] < intervals[i][0]){
                res.push_back(temp);
                temp = intervals[i];
            }
            else if(temp[1] >= intervals[i][0]){
                temp = {temp[0], max(temp[1],intervals[i][1])};
            }
        }
        res.push_back(temp);
        
        return res;
        
    }
};