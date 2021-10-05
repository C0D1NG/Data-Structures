// #26 - [https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#]
#include<bits/stdc++.h>
using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int L[n];
        int R[n];
        
        L[0] = arr[0];
        R[n-1] = arr[n-1];
        
        for(int i=1; i<n; i++)
            L[i] = max(L[i-1], arr[i]);
        
        for(int j=n-2; j>=0; j--)
           R[j] = max(R[j+1], arr[j]);
           
         int water=0;
         
         for(int i=0; i<n; i++){
             water += min(L[i], R[i])-arr[i];
         }
         
         return water;
    }
};
