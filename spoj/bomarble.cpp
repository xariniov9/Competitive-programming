#include<bits/stdc++.h>

long long dp[1005];

int main(){
    dp[0] = 0;
    dp[1] = 5;

    for(int i=2; i<=1000; i++){
        dp[i] = dp[i-1] + (long long)(i+1)*3 - 2;
    }
    int n;
    scanf("%d",&n);
    while(n!=0){
        printf("%lld\n",dp[n]);
        scanf("%d",&n);
    }
    return 0;
}
