#include <stdio.h>
int main(){
    int NUMOFSTU;
    scanf("%d",&NUMOFSTU);
    long int marks[NUMOFSTU];
    for (int i = 0; i < NUMOFSTU; i++)
    {
        scanf("%ld",&marks[i]);
        if(marks[i]<0||marks[i]>100){
            printf("INVALID INPUT");  
            return 0;
        }
    }
    int min=marks[0],max=marks[0];
    for (int i = 1; i < NUMOFSTU; i++)
    {
        if(min>marks[i]){
            min=marks[i];
        }
        if(max<marks[i]){
            max=marks[i];
        }
    }
    printf("%d %d",max,min);
}