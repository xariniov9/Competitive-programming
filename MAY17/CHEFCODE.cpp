#include<bits/stdc++.h>

using namespace std;
long long a[50];
long long k;
int n;

vector<map<long long, int> > dp(30);
map<long long, int>::iterator itr;

int solve(int idx, long long p){
    if(p>k)   return 0;
    if(idx == n) return 1;
    int ans = solve(idx + 1, p);
    if((long double) p - (long double)(1.0 * k)/(1.0 * a[idx]) >= 0.0001)
        return ans;
    return ans + solve(idx+1, p*a[idx]);
}

int p(int x){
    int ret = 1;
    for(int i=1; i<=x; i++)
        ret *= 2;
    return ret;
}

int main(){
    scanf("%d%lld",&n,&k);
    int it=0; long long x;
    for(int i=0; i<n; i++){
        scanf("%lld",&x);
        if(x!=1)
            a[it++] = x;
    }
    int mult = p(n-it);
    n = it;
    printf("%d\n",(solve(0, 1) * mult) - 1);
}
