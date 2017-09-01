#include<bits/stdc++.h>

using namespace std;

int a[3*20005];
int bits[3*20005][35];

int mxNum;
int initNum(){
    for(int i=0; i<31; i++)
        mxNum |= (1<<i);
}


void init(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=31; j++)
            bits[i][j] = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<31; j++){
            if(a[i] & (1<<j))
                bits[i][j]++;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<31; j++){
            bits[i][j] += bits[i-1][j];
        }
    }
}

int setBits(int x, int lb, int ub){
    int ret = bits[ub][x];
    if(lb>0)
        ret -= bits[lb-1][x];
    return ret;
}

int main(){
    int t;
    scanf("%d",&t);
    initNum();
   // printf("mxNum : %d\n",mxNum);
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=n; i<n+n; i++)
            a[i] = a[i-n];
        for(int i=n+n; i<n+n+n; i++)
            a[i] = a[i - n - n];
        init(3*n);
        k = min(n, k);
        for(int i=n; i<2*n; i++){
            int x = i-k;
            int y = i+k;

            int ans = 0;
            for(int j=0; j<31; j++){
                if(setBits(j, x, y) == 2*k + 1)
                    ans |= (1<<j);
            }
            printf("%d ",ans);
        }
        printf("\n");
    }
    return 0;
}
