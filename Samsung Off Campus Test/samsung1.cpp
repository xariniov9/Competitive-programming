#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[1005][1005];
long long dp[1005][1005];


#define MOD 1000000007

long long solve(int i, int j){
    if(i<0 || j<0 || i>=n || j>= m || a[i][j] == 0)
        return 0;
    if(i==n-1 && j==m-1)
        return dp[i][j] = (a[i][j]==1);
    if(dp[i][j] != -1)
        return dp[i][j];
    long long sum = (solve(i+1, j)%MOD + solve(i, j+1)%MOD)%MOD;
    sum = sum % MOD;
    sum = (sum + solve(i+1, j+1)%MOD )%MOD;
    return dp[i][j] = sum;
}


void print(int i, int j){
    if(i>=n || j>=m)
        return;
    if(i==n-1 && j==m-1){
        printf("(%d, %d)",i, j);
        return;
    }
    printf("(%d, %d)",i, j);

    if(dp[i+1][j+1] > 0)
        print(i+1, j+1);
    else if(dp[i+1][j] > 0)
        print(i+1, j);
    else
        print(i, j+1);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            scanf("%d",&a[i][j]);
    }
    memset(dp, -1, sizeof dp);

    long long ans = solve(0, 0)%MOD;
    printf("%lld\n",ans);
    if(dp[0][0])
        print(0, 0);
    else
        printf("No Path Exists");
    printf("\n");
    return 0;
}
