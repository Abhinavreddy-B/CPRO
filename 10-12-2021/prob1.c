#include <stdio.h>
#include <math.h>

int main()
{
    int NUMOFSTU, PASSMARKS;
    scanf("%d%d", &NUMOFSTU, &PASSMARKS);
    int marks[NUMOFSTU];
    int numpassed = 0;
    double percentage;
    //int sum = 0;
    //float mean, variance=0, SD;
    //int graph[11];
    int i;
    /*for (i = 0; i < 10; i++)
    {
        graph[i]=0;
    }*/
    for (i = 0; i < NUMOFSTU; i++)
    {
        scanf("%d", &marks[i]);
        if (marks[i] < 0 || marks[i] > 100)
        {
            printf("INVALID INPUT");
            return 0;
        }
        //graph[marks[i]/10]++;
    }
    for (i = 0; i < NUMOFSTU; i++)
    {
        if (marks[i] >= PASSMARKS)
        {
            numpassed++;
        }
    }
    percentage = ((double)numpassed) / NUMOFSTU;
    percentage *= 100;
    printf("%.6lf", percentage);
}
/*for (i = 0; i < NUMOFSTU; i++)
    {
        sum += marks[i];
    }
    mean = ((float)sum) / NUMOFSTU;
    for (i = 0; i < NUMOFSTU; i++)
    {
        variance += pow((marks[i] - mean), 2);
    }
    variance /= NUMOFSTU;
    SD = sqrt(variance);
    printf("for the given data , mean is %.3f ,variance is %.3f ,Standard deviation is %.3f\n\n", mean, variance, SD);
    printf("The number of students falling within\n");
    for (i = 1; mean+i*SD<=100&&mean-i*SD>=0; i++)
    {
        int count=0;
        for (int j = 0; j < NUMOFSTU; j++)
        {
            if(marks[j]<mean+i*SD&&marks[j]>mean-i*SD){
                count++;
            }
        }
        printf("Standard deviation %d is %d\n",i,count);
    }
    printf("Standard deviation %d is %d\n\n",i,NUMOFSTU);
    int min=marks[0],max=marks[0];
    for (i = 1; i < NUMOFSTU; i++)
    {
        if(min>marks[i]){
            min=marks[i];
        }
        if(max<marks[i]){
            max=marks[i];
        }
    }
    printf("Minimum mark is %d and maximum mark is %d\n\n",min,max);
    int maxgraph=graph[0];
    for (i = 1; i < 10; i++)
    {
        if(maxgraph<graph[i]){
            maxgraph=graph[i];
        }
    }
    printf("\n");
    for (int j = 0; j < maxgraph; j++)
    {
        printf("%3d| ",maxgraph-j);
        for (i = 0; i < 10; i++)
        {
            if (maxgraph-j>graph[i])
            {
                printf("       ");
            }else if(maxgraph-j==graph[i]){
                printf(".-%2d--.",graph[i]);
            }else{
                printf("|/////|");
            }
            printf(" ");
        }
        if (maxgraph-j>graph[10])
            {
                printf("       ");
            }else if(maxgraph-j==graph[10]){
                printf(".-%2d--.",graph[10]);
            }else{
                printf("|/////|");
            }
            printf(" ");
        printf("\n");
    }
    printf("_____");
    for (i = 0; i < 11; i++)
    {
        printf("________");
    }
    printf("\n");
    printf("     ");
    for (i = 0; i < 10; i++)
    {
        printf("|%2d-%2d| ",i*10,i*10+9);
    }
    printf("|99-100|");
    printf("\n");*/