#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array = ";
    cin>>n;
    int a[n], sum = 0, i;
    cout<<"Enter the elements of array = ";
    for(i=0;i<n;i++)cin>>a[i];

    for(i=0;i<n;i++)sum += a[i];

    cout<<"Sum of array elements = "<<sum;
}