/* 
Step 1 : Start
Step 2 : read values for matrix A and matrix B
Step 3 : Use the multiply function
Step 4 : check if column of first matrix is same as the row of second matrix
Step 5 : if it is false , print "Multiplication not possible" and Stop
Step 6 : if it is true , multiply the matrices
Step 7 : for each row and column , get the sum of products of the ith row and jth column of matrices
         A and B repectively.
Step 8 : assign the value to result matrix and repeat the steps until i < r1 
Step 9 : print matrix A , matrix B and the product matrix
Step 10 : Stop*/


#include<stdio.h>

void input_matrix(int arr[][20],int r,int c){
    int i,j;
    
    for(i=0;i<r;i++){
        printf("Enter row %d:",i+1);
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

void output_matrix(int arr[][20],int r,int c){
    int i,j;
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }	 	  	 	   	      	     	      	 	
    
}

int multiply(int arr1[][20],int r1,int c1,int arr2[][20],int r2,int c2,int res[][20]){
    
    int i,j,k,sum=0;
    
    if(c1!=r2){
        printf("Multiplication not possible");
        return 0;
        
    }
    else{
        
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                for(k=0;k<c2;k++){
                    sum=sum+arr1[i][k]*arr2[k][j];
                }
                res[i][j]=sum;
                sum=0;
            }
        }
        
    }
    return 1;
    
}

int main(){
    int r1,c1,arr1[20][20],r2,c2,arr2[20][20],res[20][20],flag;
    
    printf("Enter the dimentions of first matrix:");
    scanf("%d %d",&r1,&c1);
    printf("Enter the matrix A:\n");
    input_matrix(arr1,r1,c1);
    
    printf("Enter the dimentions of second matrix:");
    scanf("%d %d",&r2,&c2);
    printf("Enter the matrix B:\n");
    input_matrix(arr2,r2,c2);
    
    flag=multiply(arr1,r1,c1,arr2,r2,c2,res);
    
    if(flag){	 	  	 	   	      	     	      	 	
    printf("Matrix A:");
    output_matrix(arr1,r1,c1);
    printf("Matrix B:");
    output_matrix(arr2,r2,c2);
    printf("Matrix C = A*B:\n");
    output_matrix(res,r1,c2);
    }
    
    
    
    
return 0;
}

