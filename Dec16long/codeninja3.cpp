#include<cstdio>
#include<algorithm>

using namespace std;

long long mx = 100000000;

long long dp[200005];

long long mults[10000];

long long solve(int n, int it){
    dp[0] = 0;
    for(int i=1; i<=n; i++)
        dp[i] = mx;
    for(long long i=1; i<=n; i++){
        for(int j=0; j<it; j++){
            if(mults[j] <= i){
                long long sr = dp[i-mults[j]];
                if(sr != mx && sr+1 < dp[i])
                    dp[i] = sr+1;
            }
        }
    }
    return dp[n];
}

int main(){

    int n; long long p, q;
    scanf("%d%lld%lld",&n,&p,&q);

    long long N = 200005;

    int it=0;
    if(p>1){
        long long x=p;
        while(x<=N){
            mults[it++] = x;
            x = x*p;
        }
    }
    if(q>1){
        long long x=q;
        while(x<=N){
            mults[it++] = x;
            x = x*q;
        }
    }

   // if(p == 1 || q == 1){
        mults[it++] = 1;
    //}

    long long ans = solve(n, it);


    printf("%lld",ans);
    return 0;
}
