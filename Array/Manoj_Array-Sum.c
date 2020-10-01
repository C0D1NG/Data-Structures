#include<stdio.h>
int main()
{
	int n,arr[10];
	int sum=0;
	printf("\n Enter number of element : ");
	scanf("%d",&n);
	printf("\n\n Enter elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum=sum+arr[i];
	}
	printf("\n\n SUM = %d",sum);
	return 0;
}
