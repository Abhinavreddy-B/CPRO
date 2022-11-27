#include <stdio.h>
typedef long long ll;

int main(){
    int l,k,m;
    scanf("%d%d%d",&l,&k,&m);
    char str[l+1];
    scanf("%s",str);
    for (int i = 0; i < l-m; i+=(k-m))
    {
        for(int j=i;j<k+i&&j<l;j++){
            printf("%c",str[j]);
        }
        printf("\n");
    }
}