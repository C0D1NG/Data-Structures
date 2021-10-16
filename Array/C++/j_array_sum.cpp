/* C++ Program to find sum of elements
in a given array */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {12, 3, 4, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of given array is " << accumulate(arr, arr + n, 0);
    return 0;
}
