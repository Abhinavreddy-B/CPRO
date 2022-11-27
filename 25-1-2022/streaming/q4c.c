#include <stdio.h>

int main(int argv,char *argc[]){
    int temp;
    int n=0;
    //int sum=0;
    int count=0;
    FILE *input=fopen(argc[1],"r");
    double mean;
    FILE *meanfile=fopen(argc[2],"r");
    fscanf(meanfile,"%lf",&mean);
    fclose(meanfile);
    while(fscanf(input,"%d",&temp)!=EOF){
        //sum+=temp;
        n++;
        //mean=(double) sum/n;
        //printf("%d - %lf\n",n,mean);
        if(temp>=0.8*mean&&temp<=1.2*mean) count++;
    }
   /*printf("%lf\n%d\n%lf\n",(double) sum/n,count,( (double) count/n)*100);
    while(fscanf(input,"%d",&temp)!=EOF){
        if(temp>=0.8*mean&&temp<=1.2*mean) count++;
    }*/
    fclose(input);
    FILE *out = fopen(argc[3],"w");
    fprintf(out,"%lf\n",((double) count/n)*100);
    fclose(out);
}