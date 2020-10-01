#include <stdio.h>

int main() {
    int i,j,str[20],n,k;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf(" %d \n\nElements in arays are :\n ",n);
    for(i=0;i<n;i++){
    scanf("%d",&str[i]);
    printf("%d, ",str[i]);
    }
    printf("\n\nSteps of shorting are :\n");
    for(j=0;j<n-1;j++){
    for(i=0;i<n-1;i++){
    if(str[i]>str[i+1]){
         str[i]=str[i]+str[i+1];
         str[i+1]=str[i]-str[i+1];
         str[i]=str[i]-str[i+1];
         }
    }
    printf("step %d: ",j+1);
    for(k=0;k<n;k++)
    printf ("%d, ",str[k]);
    printf ("\n");
    }
    printf("\n\nAfter shorting ,final order is :\n");
    for(k=0;k<n;k++)
    printf ("%d ",str[k]);
    return 0;
}
