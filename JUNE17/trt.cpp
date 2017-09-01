#include<bits/stdc++.h>
using namespace std;

int a[2005];
int dp[2002][2002];
int n;

int solve(int s, int e){
    if(s==e){
        return n*a[s];
    }
    if(dp[s][e] != -1) return dp[s][e];

    int year = n - (e-s);
    return dp[s][e] = max(a[s] * year + solve(s+1, e),
               a[e] * year + solve(s, e-1));
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n",solve(0, n-1));
    return 0;
}
