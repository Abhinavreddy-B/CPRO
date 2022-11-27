#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    FILE *input=fopen("pi.txt","w");
    int inside_circle=0;
    for (int i = 0; i < 10000; i++)
    {
        double posx,posy;
        int temp=rand();
        /*if(temp%2==0){
            posx= - (temp/2.0)/RAND_MAX;
        }else{
            posx= - ((temp-1)/2.0)/RAND_MAX;
        }*/
        posx=(rand()%1000)/1000.0;
        posy=(rand()%1000)/1000.0;
        if(posx*posx+posy*posy<=1){
            inside_circle++;
        }
        if(i%100==0){
            printf("%lf\n",(4.0*inside_circle)/(i+1));
            fprintf(input,"%d\t%lf\n",i,(4.0*inside_circle)/(i+1));
        }
    }
}