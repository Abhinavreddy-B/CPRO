#include <stdio.h>
#define MAXLIMIT 10000

double find_value(int array[],double a,int n){
    double sum=0,pow=1;
    
    for (int i = 0; i <=n; i++)
    {
        sum+=array[i]*pow;
        pow*=a;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    int array[n+1];
    for(int i=n;i>=0;i--) scanf("%d",&array[i]);
    double begin=-MAXLIMIT,end=MAXLIMIT,present=0,iterations=10000000;
    while(end-begin>0.000001){
        present=(begin+end)/2;
        if(find_value(array,present,n)*find_value(array,end,n)<0){
            begin=present;
        }else if(find_value(array,begin,n)*find_value(array,present,n)<0){
            end=present;
        }else if(find_value(array,present,n)==0){
            break;
        }
        if((iterations--)==0){
            printf("Error");
            return 0;
        }
    }
    printf("%lf\n",present);
}