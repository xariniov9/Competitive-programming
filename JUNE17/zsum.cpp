#include<bits/stdc++.h>

#define MOD 10000007

int mult( long long a, long long b){
    long long temp = 1,ans = 1;
    while(b>0){
        if(b & temp){
            ans = (ans * a) % MOD;
            b = b - temp;
        }
        temp = temp << 1;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}

int main(){
 long long n,k;
 scanf("%lld%lld",&n,&k);
 while(n!=0 && k!=0){
        if(n == 0 && k == 0)
            break;
        int ans = (2*mult(n-1,k)) % MOD  +  (2*mult(n-1,n-1)) % MOD  +  mult(n,k) % MOD +  mult(n,n) % MOD;
        ans = ans % MOD;
        printf("%d\n",ans);
        scanf("%lld%lld",&n,&k);
    }
    return 0;
}
