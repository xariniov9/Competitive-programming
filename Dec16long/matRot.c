#include<stdio.h>

int main(){
    int a[4][4] = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}
                };
    int i, j, n = 4;
    for(i=0; i<n/2; i++){
        int start = i;
        int last = n-i-1;
        for(j=start; j<=last; j++){
            int temp = a[i][j];
            a[i][j] = a[j][last];
            a[j][last] = a[last][n-j-1];
            a[last][n-j-1] = a[n-j-1][start];
            a[n-j-1][start] = temp;
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
