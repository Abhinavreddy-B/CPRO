#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int array[n + 1];
    double a;
    for (int i = 0; i <=n; i++)
    {
        scanf("%d", &array[i]);
    } 
    scanf("%lf",&a);
    int sum=0,pow=1;
    
    for (int i = 0; i <=n; i++)
    {
        sum+=array[i]*pow;
        pow*=a;
    }
    printf("%d\n",sum);
}