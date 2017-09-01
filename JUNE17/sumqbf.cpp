#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007

using namespace std;

long long a[MAXN], b[MAXN], c[MAXN];

long long suma[MAXN], sumb[MAXN], sumc[MAXN];


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long p, q, r;
        scanf("%lld%lld%lld",&p,&q,&r);
        for(int i=0; i<p; i++)
            scanf("%lld",&a[i]);
        for(int i=0; i<q; i++)
            scanf("%lld",&b[i]);
        for(int i=0; i<r; i++)
            scanf("%lld",&c[i]);

        long long ans = 0;
        for(int i=0; i<p; i++){
            for(int j=0; j<q; j++){
                for(int k=0; k<r; k++){
                    if(a[i] <= b[j] && b[j] >= c[k])
                        ans += (((a[i]+b[j])%MOD) * ((b[j] + c[k])%MOD))%MOD;
                }
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
