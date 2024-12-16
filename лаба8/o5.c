#include <stdio.h>
#include <stdlib.h>

void print_matrix(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int n = 3;
    
    int a[3][4] = {{2, -3, 1, -7}, {1, 2, -3, 14}, {-1, -1, 5, -18}};
    int opr;
    if (n == 1){
        opr = a[0][0];
    }
    else if(n == 2){
        opr = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }
    else{
        opr = a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1] - a[0][2]*a[1][1]*a[2][0] - a[1][2]*a[2][1]*a[0][0] - a[0][1]*a[1][0]*a[2][2];
    }

    float opr_x, opr_y, opr_z;
    float x, y, z;

    if (n == 2){
        opr_x = (a[0][2] * a[1][1] - a[0][1] * a[1][2]);
        x = opr_x / opr;
        opr_y = (a[0][0] * a[1][2] - a[0][2] * a[1][0]);
        y = opr_y / opr;
    }
    else if (n == 3){
        opr_x = a[0][3]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][3] + a[0][2]*a[1][3]*a[2][1] - a[0][2]*a[1][1]*a[2][3] - a[1][2]*a[2][1]*a[0][3] - a[0][1]*a[1][3]*a[2][2];
        x = opr_x / opr;
        opr_y = a[0][0]*a[1][3]*a[2][2] + a[0][3]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][3] - a[0][2]*a[1][3]*a[2][0] - a[1][2]*a[2][3]*a[0][0] - a[0][3]*a[1][0]*a[2][2];
        y = opr_y / opr;
        opr_z = a[0][0]*a[1][1]*a[2][3] + a[0][1]*a[1][3]*a[2][0] + a[0][3]*a[1][0]*a[2][1] - a[0][3]*a[1][1]*a[2][0] - a[1][3]*a[2][1]*a[0][0] - a[0][1]*a[1][0]*a[2][3];
        z = opr_z / opr;
    }

    print_matrix(n,n+1,a);
    printf("x = %f, y = %f, z = %f\n", x, y, z);
}