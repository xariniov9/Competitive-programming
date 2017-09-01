// MY BAD..
// DIDN'T SEE THE CONSTRAINTS!

#include<bits/stdc++.h>

using namespace std;

/*int dp[1005][1005];
void pre(){
    dp[0][0] = 1;
    int cnt = 2;
    for(int j=1; j<=1001; j++){
        dp[0][j] = cnt;
        cnt += j+1;
    }
    for(int i=1; i<=1001; i++){
        for(int j=0; j<=1001; j++){
            dp[i][j] = dp[i-1][j+1] + 1;
        }
    }
}*/

long long calc(long long u, long long v){

    long long h = u+v;
    long long bef = (h * (h+1)) /2;
    long long diag = (u+1);
    return bef + diag;

}

int main(){
    int t;
    scanf("%d",&t);
    long long u, v;

    while(t--){
        scanf("%lld%lld",&u,&v);
        printf("%lld\n",calc(u, v));
    }

    return 0;
}
