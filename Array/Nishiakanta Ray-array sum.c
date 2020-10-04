#include <stdio.h>

int main(void) {
  //intialization
  int n,arr[10],sum=0;
  //input of range
  printf(" Enter the range of array\n ");
  scanf("%d",&n);
  //input of array element
  printf(" Enter the element of array \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  //sum of array element
  for(int i=0;i<n;i++)
    sum+=arr[i];
  //print the sum of array
  printf(" Sum of array element is%d ",sum);
  return 0;
}