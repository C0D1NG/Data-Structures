//Using MaxHeap
//Time complexity: O(nlogn)

#include<stdio.h>
void heapsort(int [],int);
void built_max_heap(int [],int);
void max_heapify(int [],int,int);
int main(){
	int n,i;
	printf("enter the size: ");
	scanf("%d",&n);
	int a[n];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	for(i=1;i<=n;i++)
	{
		printf("%d \t",a[i]);
	}
}
void heapsort(int a[],int n)
{
	int i,temp;
	int size=n;
	built_max_heap(a,n);
	for(i=n;i>=2;i--)
	{
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		n--;
		max_heapify(a,1,n);
	}
}
void built_max_heap(int a[],int n)
{
	int heapsize=n;
	int i;
	for(i=n/2;i>=1;i--)
	{
		max_heapify(a,i,n); 
	}
}
void max_heapify(int a[],int i,int n)
{
	int l=2*i;
	int r=(2*i)+1;
	int largest,temp;
	if(l<=n && a[l]>a[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if(r<=n && a[r]>a[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		max_heapify(a,largest,n);
	}
}
