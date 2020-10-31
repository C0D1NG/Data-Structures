#include <bits/stdc++.h>
using namespace std;

int findLargest(int arr[],int n){
    int maxVal = arr[0];
    for (int i = 1; i < n;i++){
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}

int main(){
    int arr1[] = {1, 2, 4, 5, 10, 8, 5};
    cout << findLargest(arr1, 7);
    return 0;
}