#include <bits/stdc++.h>

using namespace std;

int c[50];
int m;

long long dp[55][300];

long long getWays(int idx, int n){
    if(idx == m){
        return n==0;
    }
    long long ans = 0;

    if(dp[idx][n]!=-1)  return dp[idx][n];
    ans = getWays(idx+1, n);
    for(int i=1; i*c[idx] <= n; i++)
            ans += getWays(idx+1, n-i*c[idx]);
    return dp[idx][n]  = ans;
}

int main() {
    int n;
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    sort(c, c+m);
    long long ways = getWays(0, n);
    printf("%lld\n",ways);
    return 0;
}
