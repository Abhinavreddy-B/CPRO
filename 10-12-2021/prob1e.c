#include <stdio.h>

int main(){
    int NUMOFSTU;
    scanf("%d",&NUMOFSTU);
    long int marks[NUMOFSTU];
    int graph[11];
    for (int i = 0; i < 11; i++)
    {
        graph[i]=0;
    }
    
    for (int i = 0; i < NUMOFSTU; i++)
    {
        scanf("%ld",&marks[i]);
        if(marks[i]<0||marks[i]>100){
            printf("INVALID INPUT");  
            return 0;
        }
        graph[marks[i]/10]++;
    }
    for (int i = 0; i < 11; i++)
    {
        printf("%d ",graph[i]);
    }
    
}
    /*int max=graph[0];
    for (int i = 1; i < 10; i++)
    {
        if(max<graph[i]){
            max=graph[i];
        }
    }*/
    /*printf("\n");
    for (int j = 0; j < max; j++)
    {
        printf("%3d| ",max-j);
        for (int i = 0; i < 10; i++)
        {
            if (max-j>graph[i])
            {
                printf("       ");
            }else if(max-j==graph[i]){
                printf(".-%2d--.",graph[i]);
            }else{
                printf("|/////|");
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("_____");
    for (int i = 0; i < 10; i++)
    {
        printf("________");
    }
    printf("\n");
    printf("     ");
    for (int i = 0; i < 10; i++)
    {
        printf("|%2d-%2d| ",i*10,i*10+9);
    }
    printf("\n");*/
    //for (int i = 0; i < 10; i++)
    //{
    //     printf("%5d",graph[i]);
    //}
    