#include <stdio.h>

long long int solver(int n,int cols,long int array[n][n]){
    long long int det=0;
    if(n==2){
        return ((array[0][0])*(array[1][1])+(array[1][0])*(array[0][1]))%1000000007;
    }
    if(cols==n){
        return 0;
    }
    if(cols!=n){
        long int arraytemp[n-1][n-1];                     //to copy elements
        for (int i = 1; i<n; i++)
        {
            int k=0;
            for(int j=0;j<n;j++){
                if(j!=cols){
                    arraytemp[i-1][k]=array[i][j];
                    k++;
                }
            }
        }
        det+=array[0][cols]*solver(n-1,0,arraytemp);
        det%=1000000007;
        det+=solver(n,cols+1,array)%1000000007;
        det%=1000000007;
        return det;
    }
    return 0;
}

int main(){
    int n,q,base;
    scanf("%d%d",&q,&n);
    if(q==1){
        scanf("%d",&base);
    }
    long int array[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            scanf("%ld",&array[i][j]);
        }
    }
    if(n==0){
        printf("0\n");
        return 0;
    }
    if(n==1){
        printf("%ld\n",array[0][0]);
        return 0;
    }
   long long int det= solver(n,0,array);
   if(det>=100000000){
       det%=(1000000007);
   }else if(det<=-100000000){
       det%=(1000000000+7);
       det=1000000007+det;
   }
   if(q==0){
        printf("%lld\n",det);
   }else{
       char string[65];
       int i=0;
       while (det!=0)
       {
           int temp=det%base;
           if(temp<10){
               string[i]=temp+'0';
           }else{
               string[i]=temp-10+'a';
           }
           i++;
           det/=base;
       }
       for (int j = i-1; j >=0; j--)
       {
           printf("%c",string[j]);
       }
       
   }
}