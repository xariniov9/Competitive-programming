
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long r, s, p;
        scanf("%lld%lld%lld",&r,&s,&p);

        long long a=1;
        long long s1=1;
        int cnt=1;
        printf("a : 1 ");
        while(1){
            a = (a*r) % p;
            printf("%lld ",a);
            s1= (s1 + a)%p;
            cnt++;
            if(cnt == p)
                break;
        }
        printf("\n");
        if(cnt < p)
            printf("%d\n",cnt);
        else
            printf("-1\n");
    }
    return 0;
}
