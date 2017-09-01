#include<bits/stdc++.h>

using namespace std;
/*
int a[100005];
int pr[100005];
int sf[100005];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

        pr[0] = a[0] == 1 ? 1 : 0;
        sf[n-1] = a[n-1] == -1 ? 1 : 0;

        for(int i=1; i<n; i++){
            if(a[i] == 1)
                pr[i] = pr[i-1] + 1;
            else
                pr[i] = pr[i-1];
        }

        for(int i=n-2; i>=0; i--){
            if(a[i] == -1)
                sf[i] = sf[i+1] + 1;
            else
                sf[i] = sf[i+1];
        }
        int ans = 100000000;
        for(int i=0; i<n-1; i++){
            ans = min(ans, pr[i] + sf[i+1]);
        }
        printf("%d\n",ans);
    }


}
*/
/*int n;
int R[105];
int B[105];

int dp[105][105][105];
char str[205];

int solve(int idx, int red, int blue){
    if(idx == n)   return 0;

    if(dp[idx][red][blue] != -1)
        return dp[idx][red][blue];
    int ans = solve(idx+1, red, blue);
    if(red >= R[idx] && blue >= B[idx]){
        ans = max(ans, 1 + solve(idx+1, red - R[idx], blue - B[idx]));
    }
    return dp[idx][red][blue] = ans;
}
int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",str);
        for(int j=0; j<strlen(str); j++){
            if(str[j] == 'R')
                R[i]++;
            else
                B[i]++;
        }
    }
    for(int i=0; i<=101; i++)
        for(int j=0; j<=101; j++)
           for(int k=0; k<=101; k++)
                dp[i][j][k] = -1;
    int q;
    scanf("%d",&q);
    while(q--){
        int x, y;
        scanf("%d%d",&x,&y);
        int ans = solve(0, x, y);
        printf("%d\n", ans);
    }
    return 0;
}*/



int main(){
}
