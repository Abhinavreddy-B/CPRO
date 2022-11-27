#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int compar(const void *a,const void *b){
    if(*(ll*)a>*(ll*)b){
        return 1;
    }
    return 0;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    ll array[n+m];
    for (int i = 0; i < n+m; i++)
    {
        scanf("%lld",&array[i]);
    }
    qsort(array,(n+m),8,compar);
    int count=0;  
    for (int  i = 0; i < n+m-1; i++)
    {
        if(array[i]==array[i+1]){
            i++;
            count++;
        }
    }
    printf("%d",count);
}