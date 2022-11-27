#include <stdio.h>

int main(){
    long long int n1,n2;
    scanf("%lld%lld",&n1,&n2);
    if(n1<n2){
        int temp=n1;
        n1=n2;
        n2=temp;
    }
    if(n1==1||n2==1){
            printf("NO");
            return 0;
        }
    for (int i = 2; i <=n2; i++)
    {
        if(n1%i==0&&n2%i==0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}