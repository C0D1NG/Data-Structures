#include <stdio.h>
int main() {
    int i,j,result[3][3],p,q,sum=0,a=0,b=0;
    int str[3][3]={
                {1,0,0},
                {0,-1,0},
                {0,0,-1}};
    printf ("   Given Matrix\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            //scanf("%d",&str[i][j]);
            if((str[i][j]<0)||(str[i][j]>9))
            printf (" %d",str[i][j]);
            else
            printf ("  %d",str[i][j]);
        }
        printf ("\n");
    }
    for(i=0;i<3;i++){
    for(p=0;p<3;p++){
    sum=0;
    for(j=0,q=0;j<3;q++,j++){
    sum+=(str[i][j])*(str[q][p]);
    }
    result[i][p]=sum;
    printf(" ");
    }
    }
    printf ("\n\nsquare of given matrix\n\n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
        if(result[i][j]<100)
            printf ("  %d",result[i][j]);
            else
            printf (" %d",result[i][j]);
        if((i==j)&&(result[i][j]==1))
        a++;
        if((i!=j)&&(result[i][j]==0))
        b++;
        }
        printf ("\n\n");
    }
    if((a==3)&&(b==6))
    printf ("\n\nResult:\nGiven matrix is involutory matrix.");
    else
    printf ("\n\nResult:\nGiven matrix is not a involutory matrix");
    return 0;
}
