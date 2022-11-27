#include <stdio.h>
#include <math.h>

int main()
{
    int NUMOFSTU;
    scanf("%d",&NUMOFSTU);
    long int marks[NUMOFSTU];
    int sum = 0;
    double mean, SD = 0;
    for (int i = 0; i < NUMOFSTU; i++)
    {
        scanf("%ld",&marks[i]);
        if(marks[i]<0||marks[i]>100){
            printf("INVALID INPUT");  
            return 0;
        }
    }
    for (int i = 0; i < NUMOFSTU; i++)
    {
        sum += marks[i];
    }
    mean = ((double)sum) / NUMOFSTU;
    for (int i = 0; i < NUMOFSTU; i++)
    {
        SD += pow((marks[i] - mean), 2);
    }
    SD /= NUMOFSTU;
    SD = sqrt(SD);
    for (int i = 1; mean+i*SD<=100&&mean-i*SD>=0; i++)
    {
        int count=0;
        for (int j = 0; j < NUMOFSTU; j++)
        {
            if(marks[j]<=mean+i*SD&&marks[j]>=mean-i*SD){
                count++;
            }
        }
        printf("%d ",count);
    }
    printf("%d 0",NUMOFSTU);
}