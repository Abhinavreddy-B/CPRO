#include <stdio.h>

int main(){
    int rows,cols;
    scanf("%d%d",&rows,&cols);
    int matrixes[2][rows][cols];
    for (int i = 0; i < 2; i++)
    {
        for(int j=0;j<rows;j++){
            for(int k=0;k<cols;k++){
                scanf("%d",&matrixes[i][j][k]);
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for(int j=0;j<cols;j++){
            printf("%3d",matrixes[0][i][j]+matrixes[1][i][j]);  // changes to be made
        }
        printf("\n");
    }
    
}