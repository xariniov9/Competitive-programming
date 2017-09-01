#include<bits/stdc++.h>

int n, d;
int dp[1000005];

int solve(int n, int k){
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-1] + k) % i;
    }
    return dp[n] + 1;
}

int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    while(!(n == 0 && k==0)){
        printf("%d %d %d\n",n, k, solve(n, k));
        scanf("%d%d",&n,&k);
    }
    return 0;
}
