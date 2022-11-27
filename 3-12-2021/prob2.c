#include <stdio.h>

int main(){
    int n,i=1;
    printf("Enter your number:");
    scanf("%d",&n);
    start:
    printf("%d x %d = %d\n",n,i,n*i);
    i++;
    if(i<=10)
        goto start;
    return 0;
}