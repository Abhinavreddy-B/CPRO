#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    scanf("%dx^2+%dx+%d",&a,&b,&c);
    if(b*b-4*a*c<0){
        printf("Does not have real roots!\n");
        return 0;
    }
    float temp1=(-b-sqrt(b*b-4*a*c))/2.0;
    float temp2=(-b+sqrt(b*b-4*a*c))/2.0;
    if (temp1==temp2)
    {
        printf("%f\n",temp1);
    }else{
        printf("%f %f",temp1,temp2);
    }
}