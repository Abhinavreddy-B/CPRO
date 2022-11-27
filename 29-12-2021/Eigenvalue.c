#include <stdio.h>

double multiply(int n,double array[n][n],double vector[n]){
    double vector2[n];
    for (int i = 0; i < n; i++)
    {
        double temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp += array[i][j] * vector[j];
        }
        vector2[i]=temp;
    }
    double lamda=vector2[0];
    for (int i = 0; i < n; i++)
    {
        vector[i]=vector2[i]/lamda;
    }
    return lamda;
}

int main()
{
    int rows;
    scanf("%d", &rows);
    double matrix[rows][rows];
    double vector[rows];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }
    for (int i = 0; i < rows; i++)
    {
       vector[i]=1;
    }
    double lamda0,lamda1,start=2;
    while(((lamda1-lamda0)>0.1||(lamda1-lamda0)<-0.1)||start-->0){
        lamda0=lamda1;
        lamda1=multiply(rows,matrix,vector);
    }
    printf("%lf\n",lamda1);
}