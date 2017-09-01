#include<bits/stdc++.h>

using namespace std;

int dp[1000005];

int main(){
    int t;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 3;
    for(int i=5; i<=1000000; i++){
        dp[i] = dp[(i+1)/2] + 1;
    }
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
