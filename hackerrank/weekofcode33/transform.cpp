
#include<bits/stdc++.h>

using namespace std;

int n, k, m;

int p[100005];
int a[1003];
int dp[1003][1003];

void init(){
    memset(dp, -1, sizeof dp);
    for(int i=0; i<=n; i++){
        p[i] = i;
    }
}

int Find(int x){
    if(x == p[x])
        return x;
    p[x] = Find(p[x]);
    return p[x];
}

void Merge(int a, int b){
    int p1 = Find(a);
    int p2 = Find(b);
    if(p1 != p2)
        p[p2] = p1;
}

int longestPalSubs(int i, int j){
    if(j<i)
        return 0;
    if(i==j)
        return dp[i][j] = 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i+1 == j && Find(a[i]) == Find(a[j]))
        return dp[i][j] = 2;
    if(Find(a[i]) == Find(a[j]))
        return dp[i][j] = longestPalSubs(i+1, j-1) + 2;

    return dp[i][j] = max(longestPalSubs(i, j-1), longestPalSubs(i+1, j));

}

int main(){
    scanf("%d%d%d",&n,&k,&m);
    init();
    for(int i=0; i<k; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        Merge(u, v);
    }
    for(int i=0; i<m; i++)
        scanf("%d",&a[i]);
    printf("%d\n",longestPalSubs(0, m-1));
    return 0;
}
