#include <stdio.h>

int main(){
    int r1,c1,r2,c2;
    scanf("%d%d",&r1,&c1);
    r2=c1;
    long long int array1[r1][c1],array2[r1][c1];
    for(int i=0;i<r1;i++){
        for (int j = 0; j < c1; j++)
        {
           // printf("Enter element in row %d colomn %d:",i+1,j+1);
            scanf("%lld",&array1[i][j]);
        }
    }
    //printf("For array 2:\n");
    for(int i=0;i<r1;i++){
        for (int j = 0; j < c1; j++)
        {
            //printf("Enter element in row %d colomn %d:",i+1,j+1);
            scanf("%lld",&array2[i][j]);
        }
    }
    for(int i=0;i<r1;i++){
        for (int j = 0; j < c1; j++)
        {
            printf("%lld ",array1[i][j]+array2[i][j]);
        }
        printf("\n");
    }
    return 0;
}