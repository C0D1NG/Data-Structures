#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int *a;
int insert_sort(int a[],int n)
{
  int i,j;
  int c=0;
  int element;
  for(i=0;i<n;i++)
  {
    c++;
    element=a[i];
    j=i-1;
    while(j>=0 && a[j]<element)
    {
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=element;
  }
  return c;
}
void main()
{
  clock_t start,end;
  double clk;
  int count;
  int n;
  printf("Enter the number of elements of the array\n");
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
  {
    *(a+i)=rand()%100;
  }
  printf("The unsorted array is\n");
  for(int i=0;i<n;i++)
  {
  printf("%d\t",*(a+i));
}
start=clock();
count=insert_sort(a,n);
end=clock();

clk=(double)(end-start)/CLOCKS_PER_SEC;
printf("\n Result of Insertion Sort is\n");
for(int i=0;i<n;i++)
{
  printf("%d\t",*(a+i));
}
printf("\nNumber of times loop executed %d",count);
printf("\nThe run time is %f ms\n",clk);

}
