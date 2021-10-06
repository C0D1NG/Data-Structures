//algorithm used here is more efficient than bubble.c 

#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
  int array[100], n, i, j, temp;
  double start,end;int c1,c2;
  printf("Enter number of elements\n");
  scanf("%d", &n);


  for (i=0;i<n;i++)
    array[i]=rand()%100;

   start=clock();
  for (i=0;i< n-2;i++)
  { c1++;
    for (j=0;j<n-i-2;j++)
    { c2++;
      if (array[j]<array[j+1]) 
        {
        temp= array[j];
        array[j]= array[j+1];
        array[j+1]= temp;
        }
      }
    }
  
   end=clock();
   
  printf("Ascending Order\n");

  for (i=0;i<n-1;i++)
     printf("%d\t", array[i]);
     
  printf("\nThe time taken for execution is %lf ms \n",(end-start)/CLOCKS_PER_SEC);
  exit(1);
  //printf("\nThe outer loop has executed %d times, the inner loop %d times \n",c1,c2);

  
}
