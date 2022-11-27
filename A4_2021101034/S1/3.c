#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//
//Run the file as ./a.out <output file name>
//


int main(int argv,char *argc[]){
    srand(time(0));
    if(argv!=2){
        printf("Please follow the format given in the file\n");
        return 0;
    }
    FILE *output=fopen(argc[1],"w");
    int inside_circle=0;
    int count=1;
    printf("N\t\t\tvalue\n");
    fprintf(output,"N\t\t\tvalue\n");
    for (int i = 0; i < 1000000; i++)
    {
        double posx,posy;
        int temp=rand();
        if(temp%2==0){
            posx= - ((temp/2)%1000)/1000.0;
        }else{
            posx= (((temp-1)/2)%1000)/1000.0;
        }
        temp=rand();
        if(temp%2==0){
            posy= - ((temp/2)%1000)/1000.0;
        }else{
            posy= (((temp-1)/2)%1000)/1000.0;
        }
        //posx=(rand()%1000)/1000.0;
        //posy=(rand()%1000)/1000.0;
        if(posx*posx+posy*posy<=1){
            inside_circle++;
        }
        if(i==count-1||i==0){
            printf("%d\t\t\t%lf\n",i+1,(4.0*inside_circle)/(i+1));
            fprintf(output,"%d\t\t\t%lf\n",i+1,(4.0*inside_circle)/(i+1));
            count*=2;
        }
    }
}