#include<bits/stdc++.h>

int n;
int likes[21][21];


long long dp1[1<<20];

long long solveitr(){
    for(int i=0; i<(1<<n); i++)
        dp1[i] = 0;
    dp1[(1<<n) -1] =1;
    for(int i=(1<<n)-1; i>=0; i--){
        int idx = __builtin_popcount(i);
        for(int j=0; j<n; j++){
            if(likes[idx][j] == 0 || (i & (1<<j)) )
                continue;
            dp1[i] += dp1[i | (1<<j)];
        }
    }
    return dp1[0];
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d",&likes[i][j]);
            }
        }
        printf("%lld\n",solveitr());
    }
    return 0;
}
