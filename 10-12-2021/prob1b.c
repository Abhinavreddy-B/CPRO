#include <stdio.h>
#include <math.h>

int main()
{
    int NUMOFSTU;
    scanf("%d",&NUMOFSTU);
    int marks[NUMOFSTU];
    int sum = 0;
    double mean, variance=0, SD;
    for (int i = 0; i < NUMOFSTU; i++)
    {
        scanf("%d",&marks[i]);
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
        variance += (marks[i] - mean)*(marks[i] - mean);
    }
    variance /= NUMOFSTU;
    SD = sqrt(variance);
    printf("%.6lf %0.6lf %0.6lf", mean, variance, SD);
}