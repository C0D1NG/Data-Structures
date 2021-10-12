// #31 - []
#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    int temp=n;
    int rev=0;
    while(n > 0){
        rev = (rev*10)+(n%10);
        n /= 10;
    }
    
    return rev==temp;
}

/*Complete the function below*/
int PalinArray(int arr[], int n)
{  //add code here.

   for(int i=0; i<n; i++){
       if(!check(arr[i]))  return 0;
   }
   return 1;
}