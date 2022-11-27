#include <stdio.h>

int main(){
    int n1,n2,n3,temp;
    scanf("%d%d%d",&n1,&n2,&n3);
    if(n2<n3){
        temp=n2;
        n2=n3;   //shuffling so that n2>n3
        n3=temp;
    }
    if(n1<n2){
        temp=n2;
        n2=n1;    // shuffling so that n1>n2>n3
        n1=temp;
    }
    if((n3*n3+n2*n2)==n1*n1){                                           //checking if they are triplets
        printf("YES");  //printing the result
    }else{
        printf("NO");
    }
}