#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int a[1000000];
void merge(int,int,int);
void merge_sort(int low,int high)
{
    int mid;
    if(low<high)
    {
    mid=(low+high)/2;
    merge_sort(low,mid);
    merge_sort(mid+1,high);
    merge(low,mid,high);
}
}
void merge(int low,int mid,int high)
{
    int h,i,j,b[1000000],k;
    h=low;
    i=low;
    j=mid+1;
    while((h<=mid)&&(j<=high))
    {
       if(a[h]<=a[j])
       {
        b[i]=a[h];
        h++;
       }
      else
        {
          b[i]=a[j];
          j++;
       }
      i++;
       }
  if(h>mid)
    {
    for(k=j;k<=high;k++)
     {
       b[i]=a[k];
       i++;
     }
    }
  else
  {
    for(k=h;k<=mid;k++)
     {
     b[i]=a[k];
     i++;
    }
 }
  for(k=low;k<=high;k++) 
  a[k]=b[k];

  }

int main()
{
int n,i;
double starttime,endtime;
printf("Enter the number of elements:\n ");
scanf("%d",&n);
for(i=0;i<n;i++)
a[i]=rand()%100;
printf("The sorted array is:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
starttime=clock();
merge_sort(0,n-1);
endtime=clock();

printf("\nEmployee IDs in sorted order:\n");
for(i=0;i<n;i++)
{
printf("%d \t",a[i]);
}

printf("\nThe time taken for execution is %lf ms \n",(endtime-starttime)/CLOCKS_PER_SEC);
}
