#include<bits/stdc++.h>

#define TEST 0

int n;
int arr[1005][1005];

int out[1005], in[1005];

int main(){
    scanf("%d",&n);
    int t=1;
    while(n!=0){
        int f=0, s=0;
        for(int i=0; i<=n; i++)
            in[i] = out[i] = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d",&arr[i][j]);
                out[i] += arr[i][j];
                in[j] += arr[i][j];
                f += arr[i][j];
            }
        }

        if(TEST){
            printf("TEST\n");
            for(int i=0; i<n; i++)
                printf("%d ",out[i]);
            printf("\n");
        }
        for(int i=0; i<n; i++){
            s += out[i] > in[i] ? out[i] - in[i] : 0;
        }
        printf("%d. %d %d\n",t, f, s);
        t++;
        scanf("%d",&n);
    }
    return 0;
}
