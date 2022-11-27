#include <stdio.h>

int main(){
    int r1,c1,r2,c2;
    scanf("%d%d%d",&r1,&c1,&c2);
    r2=c1;
    /*if(c1!=r2){
        printf("Error");
        return 0;
    }*/
    long int array1[r1][c1],array2[r2][c2];
    long long int arraysum[r1][c2];
    for(int i=0;i<r1;i++){
        for (int j = 0; j < c1; j++)
        {
            scanf("%ld",&array1[i][j]);
        }
    }
    for(int i=0;i<r2;i++){
        for (int j = 0; j < c2; j++)
        {
            scanf("%ld",&array2[i][j]);
        }
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            arraysum[i][j]=0;
            for (int k = 0; k < c1; k++)
            {
                arraysum[i][j]+=array1[i][k]*array2[k][j];
            }
        }
    }
    for(int i=0;i<r1;i++){
        for (int j = 0; j < c2; j++)
        {
            printf("%lld ",arraysum[i][j]);
        }
        printf("\n");
    }
    return 0;
}