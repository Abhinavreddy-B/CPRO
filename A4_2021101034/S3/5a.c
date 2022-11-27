#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int array[127];
    srand(time(0));
    for (int i = 0; i < 127; i++)
    {
        array[i]=rand()%2;
       // printf("%d",array[i]);
    }
    printf("\n");
    int frequency1[2]={};
    int frequency2[2]={};
    //int pbility[2][2]={{0,0},{0,0}};
    int pos=126;
    for (int i =128; i < 100000; i++)
    {
        if(pos==126){
            array[0]=(array[0]+array[126])%2;
            pos=0;
            frequency1[array[0]]++;
            //printf("%d",array[0]);
            
               // pbility[array[0]][array[126]]++;
            
        }else{
            array[pos+1]=(array[pos]+array[pos+1])%2;
            frequency1[array[pos+1]]++;
            //printf("%d",array[pos+1]);
            
               // pbility[array[pos+1]][array[pos]]++;
           
            pos++;
        }
        frequency2[rand()%2]++;
    }
    double freq1=frequency1[0]+frequency1[1];
    double freq2=frequency2[0]+frequency2[1];
    printf("\nusing XORG\n----------\n0s-%f\t1s-%f\n",frequency1[0]/freq1,frequency1[1]/freq1);
    printf("\nusing rand\n----------\n0s-%f\t1s-%f\n\n",frequency2[0]/freq2,frequency2[1]/freq2);
   /* for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("P(xi=%d/xi-1=%d) is %f\n",i,j,((double) pbility[i][j])/(pbility[0][j]+pbility[1][j]));
        }
        
    }*/
    
}