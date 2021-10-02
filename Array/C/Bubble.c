#include<stdio.h>
void main()
{
  int i,j,n,arr[100],temp;
  printf("How many numbers do you want? ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
  	printf("\nEnter the arrays:");
  	scanf("%d",&arr[i]);
  }
  
  for(i=0;i<n-1;i++)
  for(j=0;j<n-i-1;j++)
  
  if(arr[j]>arr[j+1])
  {
  	temp=arr[j];
  	arr[j]=arr[j+1];
  	arr[j+1]=temp;
  }
  
  printf("\nArrays after sorting:\n");
  for(i=0;i<n;i++)
  {
  	printf("%d\t",arr[i]);
  }
}
