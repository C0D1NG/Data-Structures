#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print_sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<sum<<endl;
}

int main(){
    int arr[]={34,67,81,90,45};
    int len= sizeof(arr)/sizeof(arr[0]);
    print_sum(arr,len);
    return 0;
}