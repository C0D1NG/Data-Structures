#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int partition(int a[],int low,int high);
void swap(int *a,int *b);
void quick(int a[],int low,int high);
int count=0;
int partition(int a[],int low, int high)
{
  int i,j,pivot;
  i=low+1;
  j=high;
  
  pivot=a[low];
  while(i<=j)
   {
     while(a[i]<=pivot)
      {
        i++;
        count++;//to count the number of comparisons
        }
        
      while(a[j]>pivot)
      {
        j--; count++;
      }
      
      if(i<=j)
       {
         swap(&a[i],&a[j]);
         count++;
         }
         
      }
      
      swap(&a[low],&a[j]);
      count++;
      return j;
  } 
  
  void quick(int a[], int low, int high)
  {
    int mid;
    if(low<high)
      {
        mid=partition(a,low,high);
        quick(a,low,mid-1);
        quick(a,mid+1,high);
        }
        }
        
  void swap(int *a,int *b)
  {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    }
    
  int main()
   {
     double start,end;
     int n;int i;//a[100000];
     n=20;
     //printf("Enter the number of students\n");
     //scanf("%d",&n);
     //int a[20]={18,19,15,1,2,8,10,3,6,12,4,5,7,9,11,13,14,16,17,20};
     //int a[10]={100,39,99,79, 50,13,10,28,40,98};
     //int a[40]={40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11,9,7,5,3,1};
    int a[50]={49,47,45,43,41,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11,9,7,5,3,1,50,48,46,44,42,40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2};
    // for(i=0;i<n;i++)
     //{
        //scanf("%d",&a[i]);
        //a[i]=rand()%100;
      //}
      
     printf("The list of roll no is \n");
     for(i=0;i<n;i++)
       printf("%d \t",a[i]);
       
     printf("\n");
     
     start=clock();
     quick(a,0,n);
     end=clock();
     
     printf("The sorted array is \n");
     for(i=0;i<n;i++)
      printf("%d\t", a[i]);
      
     printf("\n");
     
     //printf("the number of comparisons made are %d\n",count);
     printf("The time taken by the program for execution is %lf \n", (end-start)/CLOCKS_PER_SEC);
     
     
     }
     
         
   
