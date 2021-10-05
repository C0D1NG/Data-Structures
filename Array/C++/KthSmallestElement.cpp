// #3 - [https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1]

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k){
 int max = arr[0];
 for(int i=1; i<n; i++){
     if(max < arr[i])
        max = arr[i];
    }

  int brr[max+1]{0};
  int p=0;

  for(int i=0; i<n; i++){
    p=arr[i];
    brr[p]--;
  }   

  int x=0, i=0;
     
    for( ; i<=max; i++){
        if(brr[i] != 0)
          x += abs(brr[i]);
        if(x>=k) break;
    }
    
    return i;
}

int main() {

    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout); 
    #endif
    int test;
    cin >> test;

    while(test--){
      int n;
      cin >> n; 

      int arr[n];
      for(int i=0; i<n; i++)
        cin >> arr[i];

       int k ;   cin >> k; 
      
     cout <<  kthSmallest(arr,n, k) << endl;
        
    }
    return 0;
}