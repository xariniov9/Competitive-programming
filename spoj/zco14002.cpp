#include<bits/stdc++.h>

using namespace std;
int n, a[200005];
int dp[200005][3];

int solve(int idx, int lst){
    if(idx == n){
        return 0;
    }
    if(dp[idx][lst] != -1)
        return dp[idx][lst];
    if(lst==2){
        return dp[idx][lst] = a[idx] + solve(idx+1, 0);
    }
    return dp[idx][lst] = min(solve(idx+1, lst+1), a[idx] + solve(idx+1, 0));

}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    memset(dp, -1, sizeof dp);
    printf("%d\n",solve(0, 0));
    return 0;
}
