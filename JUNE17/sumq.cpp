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

        sort(a, a+p);
        sort(b, b+q);
        sort(c, c+r);

        sumc[0] = c[0];
        for(int i=1; i<r; i++){
            sumc[i] = sumc[i-1] + c[i];
            sumc[i] %= MOD;
        }
        sumc[r] = sumc[r-1];
        for(int i=0; i<q; i++){
            long long ub = (long long)(upper_bound(c, c+r, b[i]) - c);
            sumb[i] = ((ub * b[i])%MOD + (ub>0 ? sumc[ub-1] : 0))%MOD;
            suma[i] = (b[i] * sumb[i]) % MOD;
        }
        suma[q] = sumb[q] = 0;
        for(int i=q-1; i>=0; i--){
            suma[i] = (suma[i] + suma[i+1] ) %MOD;
            sumb[i] = (sumb[i] + sumb[i+1])%MOD;
        }

        long long ans = 0;
        for(int i=0; i<p; i++){
            long long lb = (long long)(lower_bound(b, b+q, a[i]) - b);
            ans += ((a[i] * sumb[lb])%MOD + suma[lb])%MOD;
            ans %= MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
