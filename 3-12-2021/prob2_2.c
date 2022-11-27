#include <stdio.h>

int main(){
    int n,rows,i=1;
    scanf("%d",&n);
    scanf("%d",&rows);
    start:
    printf("%d\n",n*i);
    i++;
    if(i<=rows)
        goto start;
    return 0;
}