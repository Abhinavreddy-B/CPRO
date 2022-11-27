#include <stdio.h>

int main()
{
    int N;
    long int sum=0;
    scanf("%d",&N);
    long int vector[2][N];
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < N; j++)
       {
           scanf("%ld",&vector[i][j]);
       }
       
    }
    for (int i = 0; i < N; i++)
    {
        sum+=vector[0][i]*vector[1][i];
    }
    printf("%ld",sum);
}