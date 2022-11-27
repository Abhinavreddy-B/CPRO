#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ",matrix[i][j]);   ///changes to be made
        }
        printf("\n");
    }
    
}