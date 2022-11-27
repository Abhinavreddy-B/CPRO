#include <stdio.h>
double compute_value(int n,int array[n+1],double a){
    double temp=1;
    double sum=0;
    for (int i = n; i >=0&&temp!=0; i--)
    {
        sum+=array[i]*temp;
        temp*=a;
    }
    return sum;
}
double differential(int n,int array[n+1],double a){
    double temp=1;
    double sum=0;
    for (int i = n-1; i >=0; i--)
    {
        sum+=array[i]*temp*(n-i);
        temp*=a;
    }
    return sum;
}

int main(){
    int n;
    double a;
    scanf("%d",&n);
    int array[n+1];
    for (int i = 0; i < n+1; i++)
    {
        scanf("%d",&array[i]);
    }
    a=0;
    int iterations=0;
    while((compute_value(n,array,a)>0.000001||compute_value(n,array,a)<-0.000001)){
        if(iterations>=10000){
            printf("Error");
            return 0;
        }
        if(differential(n,array,a)==0){
            a++;
        }
        a=a-(compute_value(n,array,a)/differential(n,array,a));
        iterations++;
    }
    printf("%lf",a);
}