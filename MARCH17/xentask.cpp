#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        long long e1=0, o1=0, e2=0, o2=0, x;
        for(int i=0; i<n; i++){
            scanf("%lld",&x);
            if(i&1)
                o1 += x;
            else
                e1 += x;
        }
        for(int i=0; i<n; i++){
            scanf("%lld",&x);
            if(i&1)
                o2 += x;
            else
                e2 += x;
        }

        printf("%lld\n",min(e1+o2, e2+o1));
    }
    return 0;
}
