#include<bits/stdc++.h>
using namespace std;

long long a[1000005];
int dp[1000005][2];
int n;

int solve(int idx, int inc){
    if(idx == n-1)
        return 1;

    int ans = 1;
    if(dp[idx][inc] != -1)
        return dp[idx][inc];
    if(inc){
        for(int i=idx; i<n; i++){
            if(a[i] > a[idx])
                ans = max(ans, 1+solve(i, 0));
        }
    } else{
        for(int i=idx; i<n; i++){
            if(a[i] < a[idx])
                ans = max(ans, 1+solve(i, 1));
        }
    }
    return dp[idx][inc] = ans;
}

int main(){

    //int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%lld",&a[i]);
        dp[i][0] = dp[i][1] = -1;
    }
    int ans = solve(0, 1);
    memset(dp, -1, sizeof(dp));
    ans = max(ans, solve(0, 0));

    printf("%d\n",ans);
    return 0;
}
