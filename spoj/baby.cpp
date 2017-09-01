#include<bits/stdc++.h>

using namespace std;

int dp[5 + (1<<16)];int dist[20][20];
int a[20], b[20];

int tot;
int recur(int idx, int mask){
    if(idx == tot){
        return 0;
    }
    if(dp[mask] != -1)
        return dp[mask];
    int ans = 1000000000;
    for(int i=0; i<tot; i++){
        if(!(mask & (1<<i)))
            ans = min(ans,
                      dist[idx][i] +
                      recur(idx+1, mask | (1<<i)));
    }
    return dp[mask] = ans;
}

int solveItr(){
    int n =tot;
    dp[(1<<n) - 1] = 0;

    for(int i=(1<<n)-1; i>=0; i--){
        int idx = __builtin_popcount(i);
        for(int j=0; j<n; j++){
            if((i & (1<<idx)))
                continue;
            dp[i] = min(dp[i], dist[j][idx] + dp[i | (1<<j)]);
        }
    }
    return dp[0];
}

int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){

        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&b[i]);
        tot = n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dist[i][j] = abs(j-i) + abs(a[i] - b[j]);

        for(int i=0; i<(1<<n)+1; i++)
            dp[i] = -1;
        int ans = recur(0, 0);
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
