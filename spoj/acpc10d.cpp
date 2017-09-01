#include<bits/stdc++.h>

using namespace std;

int n;
int dp[100005][3];
int a[100005][3];

void initDP(){
    for(int i=0; i<=n+1; i++)
        for(int j=0; j<3; j++)
            dp[i][j] = 2000000011;
}

int solve(int i, int j){
    if(i==n-1){
        if(j==1)
            return a[i][j];
        return 2000000011;
    }
    if(dp[i][j] != 2000000011)
        return dp[i][j];
    int ans = 2000000011;
    if(j==0){
        ans = min(min(solve(i+1, 0), solve(i+1, 1)), solve(i, 1));
    } else if(j==1){
        ans = min( min(solve(i+1, 0), solve(i+1, 1)),
                   min(solve(i+1, 2), solve(i, 2))
                  );
    } else{
        ans = min( solve(i+1, 1),
                solve(i+1, 2)
                  );
    }
    return dp[i][j] = a[i][j] + ans;
}

int main(){
    int t=1;
    scanf("%d",&n);
    while(n!= 0){
        for(int i=0; i<n; i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        initDP();
        printf("%d. %d\n",t, solve(0, 1));


        scanf("%d",&n);
        t++;
    }
    return 0;
}
