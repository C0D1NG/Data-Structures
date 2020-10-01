#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void largest(int n, int array[])
{
 //to sort the array in descending order
 sort(array, array + n, greater<int>());
 cout << array[0] << " is the largest element in the array\n";
}

int main()
{
 int n, array[10000], i;
 cout << "Enter number of elements\n";
 cin >> n;
 cout << "Enter array elements\n";
 for (i = 0; i < n; i++)
 {
  cin >> array[i];
 }
 largest(n, array);

 return 0;
}