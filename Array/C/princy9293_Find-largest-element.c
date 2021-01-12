//program to find largest element in array
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[100],i,n;
	printf("enter the number of elements in array:\t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter element no. %d:\t",i+1);
	scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)      //to find largest number
	{
		if(a[0]<a[i])
		{
			a[0]=a[i];
		}
	}
	printf("largest element of array is %d",a[0]);
}

	
