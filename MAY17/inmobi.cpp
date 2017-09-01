#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n, p, dp[1005][1005];
int solve(int idx, int p){
    if(p == 0 || (idx >= n && p==0))
        return 0;
    if(idx >= n && p!=0)
        return 10000000;
    if(dp[idx][p] != -1)
        return dp[idx][p];
    int ans = solve(idx+1, p);  //reject
    ans = min(ans, max(abs(a[idx] - a[idx+1]), solve(idx + 2, p-1)));
    return dp[idx][p] = ans;
}
int main(){
    scanf("%d%d",&n,&p);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a, a+n);
    for(int i=0; i<=1000; i++)
        for(int j=0; j<=1000; j++)
            dp[i][j] = -1;
    printf("%d\n",solve(0, p));
    return 0;
}
