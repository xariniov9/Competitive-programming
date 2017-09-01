#include<bits/stdc++.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a, l, sum;
        scanf("%lld %lld %lld",&a, &l, &sum);

        long long n = (2 * sum )/(a+l);
        long long d = (l-a)/(n-5);
        long long f = a-2*d;

        printf("%lld\n",n);
        for(int i=0; i<n; i++){
            printf("%lld ",f);
            f += d;
        }
    }
    return 0;
}
